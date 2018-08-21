#include <iostream>
#include "Bus.h"
#include "Microcode.h"
#include "Register.h"
#include "Util.h"
#include "VMCore.h"

int main(int argv, char* argc) {
  std::shared_ptr<Microcode> microcode = shareM(Microcode());
  VMCore vm{microcode};

  Bus lBus{"L"};
  lBus.SetValue(8);

  Register regA("A");
  vm.Add(&regA);
  regA.AddBus(&lBus);

  mcLine(vm, stA);
  lBus.SetValue(0);
  mcLine(vm, ldA);

  std::cout << lBus.GetValue() << std::endl;

  getchar();
}