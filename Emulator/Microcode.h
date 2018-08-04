#pragma once
#include <functional>
#include <vector>
#include <iostream>
#include <map>

class Microcode {
public:
    Microcode();
    ~Microcode();

    void AddCommand(std::function<void()> command, const std::string commandName);

    void Run(std::map<std::vector<bool>::size_type,bool>* command);

public:
    std::vector<std::function<void()>> m_commands {};
    std::map<const std::string, size_t> m_command_names {};
};

