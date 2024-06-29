#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <unordered_map>

class Plugboard {
public:
    // Initialize the plugboard
    Plugboard(const std::unordered_map<char, char>& wiring);

    // Swap characters according to plugboard
    char swap(char input)const;

private:
    // Wiring of the plugboard
    std::unordered_map<char, char> wiring_;
}

#endif // PLUGBOARD_H