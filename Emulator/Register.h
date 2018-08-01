#pragma once
#include <cstdint>
#include <iostream>
#include "Component.h"

class Register :
	public Component
{
public:
	Register();
	~Register();

    void Initialise(int16_t* bus) override;
    void BusRead();


public:
    int16_t m_value;
};

