#include "VMCore.h"



VMCore::VMCore()
{

}


VMCore::~VMCore()
{
}

void VMCore::AddComponent(Component* comp)
{
    m_components.push_back(comp);
    comp->Initialise(&m_bus);
}

void VMCore::BusWrite(int16_t value) {
    m_bus = value;
}
