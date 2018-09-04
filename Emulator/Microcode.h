#pragma once
#include <functional>
#include <iostream>
#include <map>
#include <vector>
#include "MicroCommand.h"

class Microcode {
 public:
  Microcode();

  void AddCommand(std::function<void()> command, MicroCommand commandName);

  void Run(std::vector<std::pair<std::vector<bool>::size_type, bool>>* command);
  void Run(std::initializer_list<MicroCommand> command);

 public:
  std::vector<std::pair<std::function<void()>, MicroCommand>> m_commands{};
  std::map<MicroCommand, size_t> m_command_names{};
};