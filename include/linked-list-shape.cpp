#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "linked-list-shape.h"

template <typename T> LinkedListShape<T>::LinkedListShape() {}

template <typename T>
LinkedListShape<T>::LinkedListShape(std::list<T> &list,
                                    const sf::Vector2f &size,
                                    const sf::Font &font) {
    float initial_x = 0;
    for (const T &data : list) {
        nodes.push_back({size, font});
        nodes.back().setData({data, font});
        nodes.back().setLeftPosition({initial_x, 50});
        initial_x += size.x;
    }
}

template <typename T>
LinkedListShape<T>::LinkedListShape(const sf::Vector2f &, const sf::Font &) {}

template <typename T>
void LinkedListShape<T>::draw(sf::RenderTarget &window,
                              sf::RenderStates states) const {
    states.transform *= getTransform();

    for (const auto &node : nodes) {
        window.draw(node, states);
    }
}

template <typename T>
void LinkedListShape<T>::setFillColor(const sf::Color &baseColor,
                                      const sf::Color &nextColor,
                                      const sf::Color &previousColor) {
    for (auto &node : nodes) {
        node.setFillColor(baseColor, nextColor, previousColor);
    }
}

#endif // !LINKED_LIST_CPP
