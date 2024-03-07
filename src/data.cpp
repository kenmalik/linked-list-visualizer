#include "include/data.h"

Data::Data() {}

Data::Data(const std::string &string, const sf::Font &font,
           unsigned int characterSize)
    : sf::Text(string, font, characterSize) {}
