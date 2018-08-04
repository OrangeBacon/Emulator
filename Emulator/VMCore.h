#pragma once
#include <vector>
#include <cstdint>
#include "Component.h"
#include "Microcode.h"

class VMCore
{
public:
	VMCore(Microcode* microcode);
	~VMCore();

	void AddComponent(Component* comp);
    void BusWrite(int16_t value);
    int16_t BusRead();

public:
    std::vector<Component*> m_components {};
    std::shared_ptr<int16_t> m_bus;
    Microcode* m_microcode;
};

