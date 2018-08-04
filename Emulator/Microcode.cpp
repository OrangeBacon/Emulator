#include "Microcode.h"



Microcode::Microcode() {

}


Microcode::~Microcode() {

}

void Microcode::AddCommand(std::function<void()> command, const std::string commandName) {
    m_commands.push_back(command);
    m_command_names[commandName] = m_commands.size() - 1;
}

void Microcode::Run(std::map<std::vector<bool>::size_type, bool>* command) {
    for (auto key : *command) {
        if (key.second) {
            m_commands[key.first]();
        }
    }
}
