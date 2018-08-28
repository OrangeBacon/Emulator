#include "VMCore.h"

VMCore::VMCore(std::shared_ptr<Microcode> microcode) : m_microcode(microcode) {}

void VMCore::Add(Component* comp) {
  m_components.push_back(comp);
  comp->Initialise(m_microcode);
}

void mcLine(VMCore vm, std::initializer_list<const std::string> args) {
  std::vector<std::pair<std::vector<bool>::size_type, bool>> command{};
  for (const std::string i : args) {
    command.push_back(std::make_pair(vm.m_microcode->m_command_names[i], true));
  }
  vm.m_microcode->Run(&command);
}