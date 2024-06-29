#include "EnigmaMachine.h"

// Initialize Enigma machine
EnigmaMachine::EnigmaMachine(const std::vector<Rotor>& rotors, const Reflector& reflector, const Plugboard& plugboard)
    : rotors_(rotors), reflector_(reflector), plugboard_(plugboard) {}

// Function to encrypt or decrypt
std::string EnigmaMachine::encrypt(const std::string& message) {
    std::string encryptedMessage;

    // Process each character
    for (char c : message) {
        encryptedMessage += encryptChar(c);

        // Step right rotor after each character processed
        this->rotors_[0].step();

        // Handle rotor stepping for subsequent rotors
        for (size_t i = 0; i < this->rotors_.size() - 1; ++i) {
            if (this->rotors_[i].currentPosition() == this->rotors_[i].getNotch()) {
                this->rotors_[i + 1].step();
            } else {
                break;
            }
        }
    }

    return encryptedMessage;
}

// Function to encrypt single character
char EnigmaMachine::encryptChar(char input) {
    // Pass the character through the plugboard
    char c = this->plugboard_.swap(input);

    // Pass the character through rotors from right to left
    for (auto& rotor : this->rotors_) {
        c = rotor.forward(c);
    }

    // Reflect character
    c = this->reflector_.reflect(c);

    // Left to right rotors
    for (auto it = this->rotors_.rbegin(); it != this->rotors_.rend(); ++it) {
        c = it->backward(c);
    }

    return this->plugboard_.swap(c);
}