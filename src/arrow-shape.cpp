#include "arrow-shape.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

ArrowShape::ArrowShape() {}

ArrowShape::ArrowShape(const sf::Vector2f &size) : head(size.x / 6, 3) {
  body.setSize({size.x * 2 / 3 + head.getRadius() / 2, size.y / 4});

  // Position head to the right of body
  head.rotate(90);
  head.setPosition({body.getGlobalBounds().left + body.getGlobalBounds().width +
                        head.getGlobalBounds().width,
                    body.getGlobalBounds().height / 2});

  // Body centered to head
  body.move({0, head.getGlobalBounds().top + head.getGlobalBounds().height / 2 -
                    body.getGlobalBounds().height / 2});

  setOrigin(body.getGlobalBounds().left,
            body.getGlobalBounds().top + body.getGlobalBounds().height / 2);
}

void ArrowShape::draw(sf::RenderTarget &window, sf::RenderStates state) const {
  state.transform *= getTransform();

  window.draw(head, state);
  window.draw(body, state);
}

void ArrowShape::setFillColor(const sf::Color &color) {
  head.setFillColor(color);
  body.setFillColor(color);
}

sf::FloatRect ArrowShape::getGlobalBounds() {
  return sf::FloatRect(body.getGlobalBounds().left, head.getGlobalBounds().top,
                       body.getGlobalBounds().width +
                           head.getGlobalBounds().width,
                       head.getGlobalBounds().height);
}
