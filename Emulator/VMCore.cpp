#include "VMCore.h"



VMCore::VMCore(Microcode* microcode)
{
    m_microcode = microcode;
}


VMCore::~VMCore()
{
}

void VMCore::AddComponent(Component* comp)
{
    m_components.push_back(comp);
    comp->Initialise(&m_bus, m_microcode);
}

void VMCore::BusWrite(int16_t value) {
    m_bus = value;
}
