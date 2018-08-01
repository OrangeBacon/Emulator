#pragma once
#include <cstdint>
#include <iostream>

class Component
{
public:
	Component();
	virtual ~Component();

    virtual void Initialise(int16_t* bus);

protected:
    int16_t* m_bus;
};

