#ifndef DATA_H
#define DATA_H

#include <SFML/Graphics/Text.hpp>
#include <string>

class Data : public sf::Text {
private:
public:
  Data();
  Data(const std::string &string, const sf::Font &font, unsigned int characterSize = 30);
};

#endif // !DATA_H
