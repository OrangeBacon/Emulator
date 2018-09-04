#pragma once
#include <string>

class MicroCommand {
 public:
  MicroCommand(const std::string name);
  MicroCommand(const char* name);

  friend bool operator<(const MicroCommand c, const MicroCommand d) {
    return c.m_name < d.m_name;
  }

  // private:
  const std::string m_name;
};