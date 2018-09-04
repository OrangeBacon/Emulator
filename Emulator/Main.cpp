#include <iostream>
#include "ALU.h"
#include "Bus.h"
#include "Microcode.h"
#include "Register.h"
#include "Util.h"
#include "VMCore.h"

using std::make_shared;
using std::shared_ptr;

int main() {
  auto microcode = make_shared<Microcode>(Microcode{});
  VMCore vm{microcode};

  auto dataBus = make_shared<Bus>(Bus{"Data"});
  auto lBus = make_shared<Bus>(Bus{"L"});
  auto rBus = make_shared<Bus>(Bus{"R"});

  auto regA = make_shared<Register>(Register{"A"});
  vm.Add(regA);
  regA->AddBus(lBus);
  regA->AddBus(dataBus);

  auto regB = make_shared<Register>(Register{"B"});
  vm.Add(regB);
  regB->AddBus(rBus);
  regB->AddBus(dataBus);

  auto regOut = make_shared<Register>(Register{"Out"});
  vm.Add(regOut);
  regOut->AddBus(dataBus);

  auto alu = make_shared<ALU>(ALU{lBus, rBus, dataBus});
  vm.Add(alu);

  dataBus->Write(7);
  microcode->Run({stA});
  dataBus->Write(8);
  microcode->Run({stB});

  microcode->Run({ldAl, ldBr, add, stOut});

  std::cout << regA->m_value << " + " << regB->m_value << " = "
            << regOut->m_value << std::endl;

  getchar();
}