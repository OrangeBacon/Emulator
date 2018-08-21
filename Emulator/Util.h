#pragma once
#include <functional>

#define mcLine(vm, ...)                                           \
  do {                                                            \
    std::map<std::vector<bool>::size_type, bool> command{};       \
    command[vm.m_microcode->m_command_names[__VA_ARGS__]] = true; \
    vm.m_microcode->Run(&command);                                \
  } while (false)

#define shareM(name) std::make_shared<Microcode>(name)

#define stA "Bus L -> Register A"
#define ldA "Register A -> Bus L"