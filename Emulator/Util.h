#pragma once

#define mcLine(...)\
    do {\
        std::map<std::vector<bool>::size_type,bool> command {}; \
        command[microcode.m_command_names[__VA_ARGS__]] = true; \
        microcode.Run(&command); \
    } while(false)


#define bind(x) std::bind(&x, this)

#define stA "Bus -> Register A"
#define ldA "Register A -> Bus"