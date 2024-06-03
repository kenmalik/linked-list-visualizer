#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "linked-list-colors.h"
#include "node-shape.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>
#include <list>
#include <vector>

template <typename T>
class LinkedListShape : public sf::Drawable, public sf::Transformable {
  public:
    LinkedListShape();
    LinkedListShape(std::list<T> *list, const sf::Vector2f &size,
                    const sf::Font &font);
    LinkedListShape(const sf::Vector2f &, const sf::Font &);
    void draw(sf::RenderTarget &, sf::RenderStates) const;
    void setFillColor(const sf::Color &, const sf::Color &, const sf::Color &);
    void setHighlightedFillColor(const sf::Color &, const sf::Color &,
                                 const sf::Color &);
    void highlight(int index);
    void update();
    void resetColors();

  private:
    sf::Vector2f nodeSize;
    sf::Font nodeFont;
    int nodeCount = 0;
    ColorProfile defaultColorProfile;
    ColorProfile highlightedColorProfile;

    std::vector<NodeShape<T>> nodes;
    const std::list<T> *list;

    void updateShapes();
};

#include "linked-list-shape.cpp"

#endif // !LINKED_LIST_H
