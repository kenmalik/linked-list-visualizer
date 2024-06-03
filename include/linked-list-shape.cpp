#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "linked-list-shape.h"

template <typename T> LinkedListShape<T>::LinkedListShape() {}

template <typename T>
LinkedListShape<T>::LinkedListShape(std::list<T> *list,
                                    const sf::Vector2f &size,
                                    const sf::Font &font) {
    this->list = list;
    nodeCount = list->size();
    nodeSize = size;
    nodeFont = font;
    setFillColor(sf::Color::White, sf::Color::Green, sf::Color(224, 120, 22));
    setHighlightedFillColor(sf::Color::White, sf::Color::Red, sf::Color::Blue);
    updateShapes();
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
    defaultColorProfile.primary = baseColor;
    defaultColorProfile.secondary = nextColor;
    defaultColorProfile.tertiary = previousColor;
    for (auto &node : nodes) {
        node.setFillColor(baseColor, nextColor, previousColor);
    }
}

template <typename T>
void LinkedListShape<T>::setHighlightedFillColor(
    const sf::Color &baseColor, const sf::Color &nextColor,
    const sf::Color &previousColor) {
    highlightedColorProfile.primary = baseColor;
    highlightedColorProfile.secondary = nextColor;
    highlightedColorProfile.tertiary = previousColor;
}

template <typename T> void LinkedListShape<T>::update() {
    if (list->size() != nodeCount) {
        updateShapes();
        nodeCount = list->size();
    }
}

template <typename T> void LinkedListShape<T>::updateShapes() {
    nodes.clear();
    float initial_x = 0;
    for (const T &data : *(this->list)) {
        nodes.push_back({nodeSize, nodeFont});
        nodes.back().setData({data, nodeFont});
        nodes.back().setLeftPosition({initial_x, 50});
        nodes.back().setFillColor(defaultColorProfile.primary,
                                  defaultColorProfile.secondary,
                                  defaultColorProfile.tertiary);
        initial_x += nodeSize.x;
    }
}

template <typename T> void LinkedListShape<T>::highlight(int index) {
    resetColors();
    nodes.at(index).setFillColor(highlightedColorProfile.primary,
                                 highlightedColorProfile.secondary,
                                 highlightedColorProfile.tertiary);
}

template <typename T> void LinkedListShape<T>::resetColors() {
    for (auto &node : nodes) {
        node.setFillColor(defaultColorProfile.primary,
                          defaultColorProfile.secondary,
                          defaultColorProfile.tertiary);
    }
}

#endif // !LINKED_LIST_CPP
