#pragma once
#include <cstdint>
#include <iostream>
#include "Component.h"
#include "Microcode.h"
#include "Util.h"

class Register : public Component {
 public:
  Register(const std::string name);

  void Initialise(std::shared_ptr<Microcode> microcode) override;
  void AddBus(Bus* bus);

 private:
  void BusRead(std::string name);
  void BusWrite(std::string name);

  int16_t m_value;
  std::string m_name;
  std::shared_ptr<Microcode> m_microcode;
  std::map<std::string, Bus*> m_busses{};
};
