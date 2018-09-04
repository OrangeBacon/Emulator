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

  void Add(std::shared_ptr<Component> comp);

 public:
  std::vector<std::shared_ptr<Component>> m_components{};
  const std::shared_ptr<Microcode> m_microcode;
};