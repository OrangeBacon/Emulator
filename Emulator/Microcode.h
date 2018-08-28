#pragma once
#include <functional>
#include <iostream>
#include <map>
#include <vector>

class Microcode {
 public:
  Microcode();

  void AddCommand(std::function<void()> command, const std::string commandName);

  void Run(std::vector<std::pair<std::vector<bool>::size_type, bool>>* command);

 public:
  std::vector<std::pair<std::function<void()>, const std::string>> m_commands{};
  std::map<const std::string, size_t> m_command_names{};
};