#include "include/nodeptr-shape.h"
#include <SFML/Graphics/Rect.hpp>

NodePtrShape::NodePtrShape() {}

NodePtrShape::NodePtrShape(const sf::Vector2f &size)
    : base({size.x / 9, size.y}), arrow({size.x * 8 / 9, size.y / 2}) {
  arrow.setPosition(
      {base.getGlobalBounds().left + base.getGlobalBounds().width,
       base.getGlobalBounds().top + base.getGlobalBounds().height / 2});
  setOrigin(base.getGlobalBounds().left, base.getGlobalBounds().height / 2);
}

void NodePtrShape::draw(sf::RenderTarget &window,
                        sf::RenderStates state) const {
  state.transform *= getTransform();

  window.draw(base, state);
  window.draw(arrow, state);
}

void NodePtrShape::setFillColor(const sf::Color &color) {
  base.setFillColor(color);
  arrow.setFillColor(color);
}

sf::FloatRect NodePtrShape::getGlobalBounds() {
  return sf::FloatRect(
      base.getGlobalBounds().left, base.getGlobalBounds().top,
      base.getGlobalBounds().width + arrow.getGlobalBounds().width,
      base.getGlobalBounds().height);
}
