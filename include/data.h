#ifndef DATA_H
#define DATA_H

#include <SFML/Graphics/Text.hpp>

template <typename T> class Data : public sf::Text {
  private:
  public:
    Data();
    Data(const T &data, const sf::Font &font, unsigned int characterSize = 30);
};

#include "data.cpp"

#endif // !DATA_H
