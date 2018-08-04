#include "Component.h"



Component::Component()
{

}


Component::~Component()
{
}

void Component::Initialise(std::shared_ptr<int16_t> bus, Microcode* microcode) {
    m_bus = bus;
}
