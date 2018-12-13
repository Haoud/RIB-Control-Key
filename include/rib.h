#pragma once
#include <string>
#include <cstdint>

bool IsValidRIB(const std::string &rib);
void SubsituteRIBLetterByNumber(std::string &rib);
void ReadRIBOnStandartInput(uint32_t &b, uint32_t &g, uint64_t &c);
