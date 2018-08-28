#include "Bus.h"

Bus::Bus(std::string name) : m_name(name) {
  m_bus = std::make_shared<int16_t>(0);
}

int16_t Bus::Read() {
  return *m_bus;
}

void Bus::Write(int16_t value) {
  *m_bus = value;
}