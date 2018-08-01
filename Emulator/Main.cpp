#include <iostream>
#include "VMCore.h"
#include "Register.h"

int main(int argv, char* argc) {
	VMCore vm{};
    Register reg {};

    vm.AddComponent(&reg);
    vm.BusWrite(7);
    reg.BusRead();

    std::cout << reg.m_value << std::endl;

	getchar();
}