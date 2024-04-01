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
#include <vector>

void LoadFont(sf::Font &font);
void DrawToScreen(sf::RenderWindow &window,
                  const std::vector<sf::Drawable *> &drawables);

int main() {
  constexpr size_t kScreenWidth = 1280;
  constexpr size_t kScreenHeight = 720;
  sf::RenderWindow window({kScreenWidth, kScreenHeight, 32}, "Window");

  sf::Font font;
  LoadFont(font);

  NodeShape<int> node({300 * 1.5, 100 * 1.5}, font);
  node.setData({10, font});
  node.setFillColor(sf::Color::White, sf::Color::Green,
                    sf::Color(224, 120, 22));
  node.setLeftPosition({50, 150});

  std::vector<sf::Drawable *> drawables;
  drawables.push_back(&node);

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

void LoadFont(sf::Font &font) {
  const std::string font_path = "../assets/Ubuntu-R.ttf";
  if (!font.loadFromFile(font_path)) {
    std::cerr << "Cannot load font at " << font_path;
    exit(1);
  }
}

void DrawToScreen(sf::RenderWindow &window,
                  const std::vector<sf::Drawable *> &drawables) {
  window.clear();
  for (const auto &drawable : drawables) {
    window.draw(*drawable);
  }
  window.display();
}
