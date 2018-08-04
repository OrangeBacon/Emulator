#include "Register.h"

Register::Register(std::string name) : m_name(name) {
    
}

Register::~Register()
{

}

void Register::Initialise(std::shared_ptr<int16_t> bus, Microcode* microcode) {
    Component::Initialise(bus, microcode);
    microcode->AddCommand(bind(Register::BusRead), "Bus -> Register " + m_name);
    microcode->AddCommand(bind(Register::BusWrite), "Register " + m_name + " -> Bus");
}

void Register::BusRead() {
    m_value = *m_bus;
}

void Register::BusWrite() {
    *m_bus = m_value;
}