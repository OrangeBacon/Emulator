#include "Microcode.h"

Microcode::Microcode() {}

void Microcode::AddCommand(std::function<void()> command,
                           MicroCommand commandName) {
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

void Microcode::Run(std::initializer_list<MicroCommand> args) {
  std::vector<std::pair<std::vector<bool>::size_type, bool>> command{};
  for (auto i : args) {
    command.push_back(std::make_pair(m_command_names[i.m_name], true));
  }
  Run(&command);
}