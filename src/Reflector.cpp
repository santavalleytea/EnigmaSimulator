#include "Reflector.h"

// Initialize reflector
Reflector::Reflector(const std::string& wiring)
    : wiring_(wiring) {}

char Reflector::reflect(char input) const {
    // Calculate index of the input character
    int index = input - 'A';

    return wiring_[index];
}