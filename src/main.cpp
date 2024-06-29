#include "EnigmaMachine.h"
#include <iostream>
#include <unordered_map>

int main() {
    // Define rotors with their wirings and notch
    std::vector<Rotor> rotors = {
        Rotor("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q'),
        Rotor("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E'),
        Rotor("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V')
    };

    // Define the reflector wiring
    Reflector reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT");

    // Define the plugboard wiring
    std::unordered_map<char, char> plugboardWiring = {
        {'A', 'B'}, {'B', 'A'},
        {'C', 'D'}, {'D', 'C'}, 
    };
    Plugboard plugboard(plugboardWiring);

    // Initialize with the defined components
    EnigmaMachine enigma(rotors, reflector, plugboard);

    // Message to encrypt
    std::string message = "HELLO";
    std::string encryptedMessage = enigma.encrypt(message);

    // Output
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl;

    return 0;
}