#include "VMCore.h"



VMCore::VMCore(Microcode* microcode)
{
    m_microcode = microcode;
    m_bus = std::make_shared<int16_t>(0);
}


VMCore::~VMCore()
{
}

void VMCore::AddComponent(Component* comp)
{
    m_components.push_back(comp);
    comp->Initialise(m_bus, m_microcode);
}

void VMCore::BusWrite(int16_t value) {
    *m_bus = value;
}

int16_t VMCore::BusRead() {
    return *m_bus;
}