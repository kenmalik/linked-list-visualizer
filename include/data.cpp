#include "data.h"
#include <sstream>

template <typename T> Data<T>::Data() {}

template <typename T>
Data<T>::Data(const T &data, const sf::Font &font, unsigned int characterSize)
    : sf::Text("", font, characterSize) {
  std::ostringstream ss;
  ss << data;
  setString(ss.str());
}
