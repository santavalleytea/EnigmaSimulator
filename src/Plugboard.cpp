#include "Plugboard.h"

// Initializes plugboard
Plugboard::Plugboard(const std::unordered_map<char, char>& wiring)
    : wiring_(wiring) {}

// Swap characters
char Plugboard::swap(char input) const {
    // Check if input is in wiring map
    auto it = wiring_.find(input);

    return it != wiring_.end() ? it->second : input;
}