#ifndef ENIGMAMACHINE_H
#define ENIGMAMACHINE_H

#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"
#include <vector>
#include <string>

// EnigmaMachine class represents the machine itself
class EnigmaMachine {
public:
    // Constructor that initialize the Enigma machine
    EnigmaMachine(const std::vector<Rotor>& rotors, const Reflector& reflector, const Plugboard& plugboard);

    // Encrypt or decrypt message
    std::string encrypt(const std::string& message);

private:
    // Vector of rotors
    std::vector<Rotor> rotors_;

    // Reflector
    Reflector reflector_;

    // Plugboard
    Plugboard plugboard_;

    // Encrypt a single character
    char encryptChar(char input);
};

#endif // ENIGMAMACHINE_H