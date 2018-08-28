#pragma once
#include <cstdint>
#include <iostream>
#include <memory>
#include "Bus.h"
#include "Microcode.h"

class Component {
 public:
  virtual void Initialise(std::shared_ptr<Microcode> microcode) = 0;
};
