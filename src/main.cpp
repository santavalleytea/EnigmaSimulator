#include "EnigmaMachine.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

void configurePlugboard(std::unordered_map<char, char>& plugboardWiring) {
    std::string pairs;
    std::cout << "Enter plugboard pairs: ";
    std::getline(std::cin, pairs);
    for (size_t i = 0; i < pairs.length(); i+= 3) {
        plugboardWiring[pairs[i]] = pairs[i + 1];
        plugboardWiring[pairs[i + 1]] = pairs[i];
    }
}

int main() {
    // Define rotors with their wirings and notch
    std::vector<std::string> rotorWiring = {
        "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
        "AJDKSIRUXBLHWTMCQGZNPYFVOE",
        "BDFHJLCPRTXVZNYEIWGAKMUSQO"
    };
    std::vector<char> rotorNotches = {'Q', 'E', 'V'};

    std::vector<Rotor> rotors;
    for (size_t i = 0; i < rotorWiring.size(); ++i) {
        rotors.emplace_back(rotorWiring[i], rotorNotches[i]);
    }

    // Define the reflector wiring
    Reflector reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT");

    // Define the plugboard wiring
    std::unordered_map<char, char> plugboardWiring;
    configurePlugboard(plugboardWiring);
    Plugboard plugboard(plugboardWiring);

    // Initialize with the defined components
    EnigmaMachine enigma(rotors, reflector, plugboard);

    // Message to encrypt
    std::string message;
    std::cout << "Enter message to encrypt: ";
    std::getline(std::cin, message);

    // Encrypt message
    std::string encryptedMessage = enigma.encrypt(message);
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl;

    return 0;
}