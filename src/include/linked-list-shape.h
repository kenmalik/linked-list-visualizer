#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node-shape.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <vector>

class LinkedListShape : public sf::Drawable, public sf::Transformable {
private:
  std::vector<NodeShape> nodes;

public:
  LinkedListShape();
  LinkedListShape(const sf::Vector2f &, const sf::Font &);
  void draw(sf::RenderTarget &, sf::RenderStates) const;
  void setFillColor(const sf::Color &, const sf::Color &, const sf::Color &);
};

#endif // !LINKED_LIST_H
