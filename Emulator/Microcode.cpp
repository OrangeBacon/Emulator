#include "Microcode.h"



Microcode::Microcode() {

}


Microcode::~Microcode() {

}

void Microcode::AddCommand(std::function<void()> command, const std::string& commandName) {
    m_commands.push_back(command);
    m_command_names[commandName] = m_commands.size() - 1;
}

void Microcode::Run(std::vector<bool>* command) {
    for (std::vector<bool>::size_type i = 0; i < command->size(); ++i) {
        if (command->operator[](i)) {
            m_commands[i]();
        }
    }
}
