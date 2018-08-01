#pragma once
#include <vector>
#include <cstdint>
#include "Component.h"

class VMCore
{
public:
	VMCore();
	~VMCore();

	void AddComponent(Component* comp);
    void BusWrite(int16_t value);

public:
	std::vector<Component*> m_components{};
    int16_t m_bus;
};

