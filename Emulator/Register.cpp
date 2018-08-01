#include "Register.h"



Register::Register()
{
}


Register::~Register()
{
}

void Register::Initialise(int16_t * bus) {
    Component::Initialise(bus);
}

void Register::BusRead() {
    m_value = *m_bus;
}
