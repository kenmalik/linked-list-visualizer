#ifndef ARROW_H
#define ARROW_H

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>

class ArrowShape : public sf::Drawable, public sf::Transformable {
private:
  sf::RectangleShape body;
  sf::CircleShape head;

public:
  ArrowShape();
  ArrowShape(const sf::Vector2f &);
  void draw(sf::RenderTarget &, sf::RenderStates) const;
  void setFillColor(const sf::Color &);
  sf::FloatRect getGlobalBounds();
};

#endif // !ARROW_H
