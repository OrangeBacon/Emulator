#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include "Bus.h"
#include "Component.h"
#include "Microcode.h"
#include "Util.h"

class VMCore {
 public:
  VMCore(std::shared_ptr<Microcode> microcode);

  void Add(Component* comp);

 public:
  std::vector<Component*> m_components{};
  const std::shared_ptr<Microcode> m_microcode;
};

void mcLine(VMCore vm, std::initializer_list<const std::string> args);