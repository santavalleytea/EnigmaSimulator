#ifndef ROTOR_H
#define ROTOR_H

#include <string>
#include <vector>

// Representing a single rotor 
class Rotor {
public:
    // Initialize rotor with a given wiring and notch position
    Rotor(const std::string& wiring, char notch);
    // Function to map a character through rotor from right to left
    char forward(char input);
    // Function to map a character through the rotor from left to right
    char backward(char input);
    // Function to step rotor forward by one
    void step();
    // Get current position of rotor
    char currentPosition() const;

private:
    // Wiring of the rotor (permutation of the alphabet)
    std::string wiring_;
    // The reverse wiring of the rotor
    std::string reverseWiring_;
    // Notch position
    char notch_;
    // Current position of rotor
    int position_;
    // Helper functions
    char mapForward(char input);
    char mapBackward(char input);
    void createReverseWiring();
};

#endif // ROTOR_H
