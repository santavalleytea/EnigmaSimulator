#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <string>

class Reflector {
public:
    // Initializes reflector with a given wiring
    Reflector(const std::string& wiring);

    // Reflect a character according to wiring
    char reflect(char input) const;

private:
    // Wiring of the reflector
    std::string wiring_;
};

#endif // REFLECTOR_H