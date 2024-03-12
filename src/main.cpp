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
  if (!font.loadFromFile("Ubuntu-R.ttf")) {
    std::cerr << "Cannot load font";
  }

  LinkedList<int> list;
  list.first_node({1, nullptr, nullptr});
  std::cout << list.getHead()->data << std::endl;

  ArrowShape arrow({200, 50});
  arrow.setPosition({500, 500});

  NodeShape node({300 * 1.5, 100 * 1.5}, font);
  node.setData({"New data", font});
  node.setPosition(250, 250);
  node.setFillColor(sf::Color::White, sf::Color::Green,
                    sf::Color(224, 120, 22));
  sf::Vector2f nodeVelocity(.2, 0);
  float nodeAngularVelocity = .1;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    if (node.getPosition().x > kScreenWidth || node.getPosition().x < 0) {
      nodeVelocity = -nodeVelocity;
      nodeAngularVelocity = -nodeAngularVelocity;
    }
    arrow.rotate(.1);
    node.rotate(nodeAngularVelocity);
    node.move(nodeVelocity);
    window.clear();

    window.draw(arrow);

    window.draw(node);

    window.display();
  }

  return 0;
}
