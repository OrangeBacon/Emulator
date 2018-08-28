#include "ALU.h"

ALU::ALU(shared_ptr<Bus> l, shared_ptr<Bus> r, shared_ptr<Bus> out) {
  m_lBus = l;
  m_rBus = r;
  m_outBus = out;
}

void ALU::Initialise(shared_ptr<Microcode> microcode) {
  microcode->AddCommand(std::bind(&ALU::Add, this), "Add");
}

void ALU::Add() {
  m_outBus->Write(m_lBus->Read() + m_rBus->Read());
}