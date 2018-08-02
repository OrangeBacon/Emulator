#pragma once
#include <cstdint>
#include <iostream>
#include "Microcode.h"

class Component
{
public:
	Component();
	virtual ~Component();

    virtual void Initialise(int16_t* bus, Microcode* microcode);

protected:
    int16_t* m_bus;
};

