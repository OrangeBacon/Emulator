#pragma once
#include <cstdint>
#include <iostream>
#include "Microcode.h"

class Component
{
public:
	Component();
	virtual ~Component();

    virtual void Initialise(std::shared_ptr<int16_t> bus, Microcode* microcode);

protected:
    std::shared_ptr<int16_t> m_bus;
};

