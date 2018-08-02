#pragma once
#include <cstdint>
#include <iostream>
#include "Component.h"

class Register :
	public Component
{
public:
	Register(const std::string& name);
	~Register();

    void Initialise(int16_t* bus, Microcode* microcode) override;

private:
    void BusRead();
public:
    int16_t m_value;
    const std::string& m_name;
};

