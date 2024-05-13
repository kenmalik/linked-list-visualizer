#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node-shape.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <list>
#include <vector>

template <typename T>
class LinkedListShape : public sf::Drawable, public sf::Transformable {
  private:
    std::vector<NodeShape<T>> nodes;

  public:
    LinkedListShape();
    LinkedListShape(std::list<T> &list, const sf::Vector2f &size,
                    const sf::Font &font);
    LinkedListShape(const sf::Vector2f &, const sf::Font &);
    void draw(sf::RenderTarget &, sf::RenderStates) const;
    void setFillColor(const sf::Color &, const sf::Color &, const sf::Color &);
};

#include "linked-list-shape.cpp"

#endif // !LINKED_LIST_H
