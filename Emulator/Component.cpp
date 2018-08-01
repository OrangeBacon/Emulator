#include "Component.h"



Component::Component()
{
}


Component::~Component()
{
}

void Component::Initialise(int16_t * bus) {
    m_bus = bus;
}
