#include "node-shape.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

template <typename T>
NodeShape<T>::NodeShape() {}

template <typename T>
NodeShape<T>::NodeShape(const sf::Vector2f &size, const sf::Font &font)
    : base({size.x * 2 / 8, size.y}), next({size.x * 3 / 8, size.y}),
      previous({size.x * 3 / 8, size.y}), data() {
  data.setFillColor(sf::Color::Black);
  previous.setRotation(180);
  previous.move(previous.getGlobalBounds().width, 0);
  base.move(previous.getGlobalBounds().width,
            -base.getGlobalBounds().height / 2);
  next.setPosition(base.getGlobalBounds().left + base.getGlobalBounds().width,
                   base.getGlobalBounds().top +
                       base.getGlobalBounds().height / 2);

  data.setOrigin(data.getGlobalBounds().left + data.getGlobalBounds().width / 2,
                 data.getGlobalBounds().top +
                     data.getGlobalBounds().height / 2);
  data.setPosition(
      base.getGlobalBounds().left + base.getGlobalBounds().width / 2,
      base.getGlobalBounds().top + base.getGlobalBounds().height / 2);
  setOrigin(base.getGlobalBounds().left + base.getGlobalBounds().width / 2,
            base.getGlobalBounds().top + base.getGlobalBounds().height / 2);
}

template <typename T>
void NodeShape<T>::draw(sf::RenderTarget &window, sf::RenderStates state) const {
  state.transform *= getTransform();

  window.draw(base, state);
  window.draw(next, state);
  window.draw(previous, state);
  window.draw(data, state);
}

template <typename T>
void NodeShape<T>::setFillColor(const sf::Color &baseColor,
                             const sf::Color &nextColor,
                             const sf::Color &previousColor) {
  base.setFillColor(baseColor);
  next.setFillColor(nextColor);
  previous.setFillColor(previousColor);
}

template <typename T>
void NodeShape<T>::setData(const Data<T> &data) {
  this->data = data;
  this->data.setFillColor(sf::Color::Black);
  this->data.setOrigin(this->data.getGlobalBounds().left + this->data.getGlobalBounds().width / 2,
                 this->data.getGlobalBounds().top +
                     this->data.getGlobalBounds().height / 2);
  this->data.setPosition(
      base.getGlobalBounds().left + base.getGlobalBounds().width / 2,
      base.getGlobalBounds().top + base.getGlobalBounds().height / 2);
}

template <typename T>
void NodeShape<T>::setLeftPosition(const sf::Vector2f &pos) {
  setPosition(pos);
  move(base.getGlobalBounds().width * 2, 0);
}

template <typename T>
void NodeShape<T>::setRightPosition(const sf::Vector2f &pos) {
  setPosition(pos);
  move(base.getGlobalBounds().width * -2, 0);
}
