#pragma once

#define mcInsert(vector, name) \
    vector.insert(vector.begin()+ microcode.m_command_names[name], true);

#define mcLine(lineName, ...) \
    std::vector<bool> lineName; \
    mcInsert(lineName, __VA_ARGS__);