#ifndef NODEPTR_H
#define NODEPTR_H

#include "arrow-shape.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

class NodePtrShape : public sf::Drawable, public sf::Transformable {
private:
  ArrowShape arrow;
  sf::RectangleShape base;

public:
  NodePtrShape();
  NodePtrShape(const sf::Vector2f &);
  void draw(sf::RenderTarget &, sf::RenderStates) const;
  void setFillColor(const sf::Color &);
  sf::FloatRect getGlobalBounds();
};

#endif // !NODEPTR_H
