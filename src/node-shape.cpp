#include "include/node-shape.h"

NodeShape::NodeShape() {}

NodeShape::NodeShape(const sf::Vector2f &size, const sf::Font &font)
    : base({size.x * 2 / 8, size.y}), next({size.x * 3 / 8, size.y}),
      previous({size.x * 3 / 8, size.y}), data("Data", font) {
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

void NodeShape::draw(sf::RenderTarget &window, sf::RenderStates state) const {
  state.transform *= getTransform();

  window.draw(base, state);
  window.draw(next, state);
  window.draw(previous, state);
  window.draw(data, state);
}

void NodeShape::setFillColor(const sf::Color &baseColor,
                             const sf::Color &nextColor,
                             const sf::Color &previousColor) {
  base.setFillColor(baseColor);
  next.setFillColor(nextColor);
  previous.setFillColor(previousColor);
}

void NodeShape::setData(const Data &data) {
  this->data = data;
  this->data.setFillColor(sf::Color::Black);
  this->data.setOrigin(this->data.getGlobalBounds().left + this->data.getGlobalBounds().width / 2,
                 this->data.getGlobalBounds().top +
                     this->data.getGlobalBounds().height / 2);
  this->data.setPosition(
      base.getGlobalBounds().left + base.getGlobalBounds().width / 2,
      base.getGlobalBounds().top + base.getGlobalBounds().height / 2);
}
