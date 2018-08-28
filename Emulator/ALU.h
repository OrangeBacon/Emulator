#pragma once
#include <memory>
#include "Bus.h"
#include "Component.h"
#include "Util.h"

using std::make_shared;
using std::shared_ptr;

class ALU : public Component {
 public:
  ALU(shared_ptr<Bus>, shared_ptr<Bus>, shared_ptr<Bus>);
  void Initialise(shared_ptr<Microcode> microcode);

 private:
  void Add();
  shared_ptr<Bus> m_rBus;
  shared_ptr<Bus> m_outBus;
  shared_ptr<Bus> m_lBus;
};