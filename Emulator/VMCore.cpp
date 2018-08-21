#include "VMCore.h"

VMCore::VMCore(std::shared_ptr<Microcode> microcode) : m_microcode(microcode) {}

void VMCore::Add(Component* comp) {
  m_components.push_back(comp);
  comp->Initialise(m_microcode);
}