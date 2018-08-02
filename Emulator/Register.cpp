#include "Register.h"



Register::Register(const std::string& name) : m_name(name) {
}

Register::~Register()
{

}

void Register::Initialise(int16_t * bus, Microcode* microcode) {
    Component::Initialise(bus, microcode);
    microcode->AddCommand(std::bind(&Register::BusRead, this), "Bus -> Register " + m_name);
}

void Register::BusRead() {
    m_value = *m_bus;
}
