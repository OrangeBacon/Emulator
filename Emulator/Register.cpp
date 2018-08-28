#include "Register.h"

Register::Register(std::string name) : m_name(name) {}

void Register::Initialise(std::shared_ptr<Microcode> microcode) {
  m_microcode = microcode;
}

void Register::AddBus(std::shared_ptr<Bus> bus) {
  m_busses[bus->m_name] = bus;

  m_microcode->AddCommand(std::bind(&Register::BusRead, this, bus->m_name),
                          "Bus " + bus->m_name + " -> Register " + m_name);

  m_microcode->AddCommand(std::bind(&Register::BusWrite, this, bus->m_name),
                          "Register " + m_name + " -> Bus " + bus->m_name);
}

void Register::BusRead(std::string name) {
  m_value = m_busses[name]->Read();
}

void Register::BusWrite(std::string name) {
  m_busses[name]->Write(m_value);
}