#include <iostream>
#include "VMCore.h"
#include "Register.h"
#include "Microcode.h"
#include "Util.h"

int main(int argv, char* argc) {
    Microcode microcode {};
    VMCore vm {&microcode};
    
    Register reg("A");

    vm.AddComponent(&reg);
    vm.BusWrite(7);
    
    mcLine(stA);
    vm.BusWrite(0);
    std::cout << reg.m_value << std::endl;
    mcLine(ldA);

    std::cout << vm.BusRead() << std::endl;

	getchar();
}