#include "data.h"
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

int main() {
  constexpr size_t kScreenWidth = 1280;
  constexpr size_t kScreenHeight = 720;

  sf::Font font;
  if (!font.loadFromFile("../assets/Ubuntu-R.ttf")) {
    std::cerr << "Cannot load font";
    exit(1);
  }

  sf::RenderWindow window({kScreenWidth, kScreenHeight, 32}, "Window");

  NodeShape<int> node({300 * 1.5, 100 * 1.5}, font);
  node.setData({10, font});
  node.setFillColor(sf::Color::White, sf::Color::Green,
                    sf::Color(224, 120, 22));
  node.setLeftPosition({50, 150});

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();

    window.draw(node);

    window.display();
  }

  return 0;
}
