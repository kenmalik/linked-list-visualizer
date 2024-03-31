#include "data.h"
#include "arrow-shape.h"
#include "node-shape.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "linked-list.hpp"

int main() {
  constexpr size_t kScreenWidth = 1280;
  constexpr size_t kScreenHeight = 720;

  sf::RenderWindow window({kScreenWidth, kScreenHeight, 32}, "Window");

  sf::Font font;
  if (!font.loadFromFile("../assets/Ubuntu-R.ttf")) {
    std::cerr << "Cannot load font";
    exit(1);
  }

  LinkedList<int> list;
  list.push_back(1);
  list.push_front(2);
  std::cout << list << std::endl;

  NodeShape node({300 * 1.5, 100 * 1.5}, font);
  node.setData({"New data", font});
  node.setFillColor(sf::Color::White, sf::Color::Green,
                    sf::Color(224, 120, 22));
  node.setLeftPosition({0, 0});

  NodeShape node2({300 * 1.5, 100 * 1.5}, font);
  node2.setData({"Other data", font});
  node2.setFillColor(sf::Color::White, sf::Color::Green,
                    sf::Color(224, 120, 22));
  node2.setRightPosition({kScreenWidth, 0});

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();

    window.draw(node);
    window.draw(node2);

    window.display();
  }

  return 0;
}
