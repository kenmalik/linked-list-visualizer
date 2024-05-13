#include "data.h"
#include "linked-list-shape.h"
#include "node-shape.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

#include <iostream>
#include <memory>
#include <vector>

std::unique_ptr<sf::Font> LoadFont();
void DrawToScreen(sf::RenderWindow &window,
                  const std::vector<sf::Drawable *> &drawables);

int main() {
    constexpr size_t kScreenWidth = 1280;
    constexpr size_t kScreenHeight = 720;
    sf::RenderWindow window({kScreenWidth, kScreenHeight, 32}, "Window");

    auto font = LoadFont();
    if (!font) {
        exit(1);
    }

    std::vector<sf::Drawable *> drawables;

    NodeShape<int> node({150, 50}, *font);
    node.setData({10, *font});
    node.setFillColor(sf::Color::White, sf::Color::Green,
                      sf::Color(224, 120, 22));
    node.setLeftPosition({50, 150});
    drawables.push_back(&node);

    std::list<int> list{1, 2, 3};
    LinkedListShape<int> list_shape(list, {150, 50}, *font);
    list_shape.setFillColor(sf::Color::White, sf::Color::Green,
                            sf::Color(224, 120, 22));
    drawables.push_back(&list_shape);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        DrawToScreen(window, drawables);
    }

    return 0;
}

std::unique_ptr<sf::Font> LoadFont() {
    const std::string kFontPath = "../assets/Ubuntu-R.ttf";
    std::unique_ptr<sf::Font> font(new sf::Font());
    if (!font->loadFromFile(kFontPath)) {
        std::cerr << "Cannot load font at " << kFontPath;
        return nullptr;
    }
    return font;
}

void DrawToScreen(sf::RenderWindow &window,
                  const std::vector<sf::Drawable *> &drawables) {
    window.clear();
    for (const auto &drawable : drawables) {
        window.draw(*drawable);
    }
    window.display();
}
