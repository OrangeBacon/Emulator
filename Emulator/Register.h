#pragma once
#include <cstdint>
#include <iostream>
#include "Component.h"
#include "Util.h"

class Register :
	public Component
{
public:
	Register(const std::string name);
	~Register();

    void Initialise(std::shared_ptr<int16_t> bus, Microcode* microcode) override;

private:
    void BusRead();
    void BusWrite();

public:
    int16_t m_value;
    std::string m_name;
};

