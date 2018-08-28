#include "Microcode.h"

Microcode::Microcode() {}

void Microcode::AddCommand(std::function<void()> command,
                           const std::string commandName) {
  m_commands.push_back(std::make_pair(command, commandName));
  m_command_names.insert(std::make_pair(commandName, m_commands.size() - 1));
}

void Microcode::Run(
    std::vector<std::pair<std::vector<bool>::size_type, bool>>* command) {
  for (auto key : *command) {
    if (key.second) {
      m_commands[key.first].first();
    }
  }
}
