#ifndef NODE_H
#define NODE_H

#include "data.h"
#include "nodeptr-shape.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

class NodeShape : public sf::Drawable, public sf::Transformable {
private:
  sf::RectangleShape base;
  NodePtrShape next;
  NodePtrShape previous;
  Data data;

public:
  NodeShape();
  NodeShape(const sf::Vector2f &, const sf::Font &);
  void draw(sf::RenderTarget &, sf::RenderStates) const;
  void setFillColor(const sf::Color &, const sf::Color &, const sf::Color &);
  void setData(const Data &data);
  void setLeftPosition(const sf::Vector2f &pos);
  void setRightPosition(const sf::Vector2f &pos);
};

#endif // !NODE_H
