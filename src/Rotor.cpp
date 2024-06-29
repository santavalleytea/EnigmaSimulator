#include "Rotor.h"
#include <algorithm>

// Initialize rotor with a given wiring and notch position
Rotor::Rotor(const std::string& wiring, char notch)
    : wiring_(wiring), notch_(notch), position_(0) {
    
    createReverseWiring();
}

// Map a character through rotor from right to left
char Rotor::forward(char input) {
    return mapForward(input);
}

// Map a character through rotor from left to right
char Rotor::backward(char input) {
    return  mapBackward(input);
}

// Step rotor forward by one
void Rotor::step() {
    position_ = (position_ + 1) % 26;
}

// Get current position
char Rotor::currentPosition() const {
    return 'A' + position_;
}

// Helper function for forward rotor
char Rotor::mapForward(char input) {
    int index = (input - 'A' + position_) % 26;
    return wiring_[index];
}

// Helper function for backward rotor
char Rotor::mapBackward(char input) {
    int index = (input - 'A' + position_) % 26;
    return reverseWiring_[index];
}

// Reverse wiring based on forward wiring
void Rotor::createReverseWiring() {
    reverseWiring_.resize(26);

    for (size_t i = 0; i < 26; ++i) {
        reverseWiring_[wiring_[i] - 'A'] = 'A' + i;
    }
}