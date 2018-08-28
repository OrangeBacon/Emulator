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

  Register regA{"A"};
  vm.Add(&regA);
  regA.AddBus(lBus);
  regA.AddBus(dataBus);

  Register regB{"B"};
  vm.Add(&regB);
  regB.AddBus(rBus);
  regB.AddBus(dataBus);

  Register regOut{"Out"};
  vm.Add(&regOut);
  regOut.AddBus(dataBus);

  ALU alu{lBus, rBus, dataBus};
  vm.Add(&alu);

  dataBus->Write(7);
  mcLine(vm, {stA});
  dataBus->Write(8);
  mcLine(vm, {stB});

  mcLine(vm, {ldAl, ldBr, add, stOut});

  std::cout << regA.m_value << " + " << regB.m_value << " = " << regOut.m_value
            << std::endl;

  getchar();
}