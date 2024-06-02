#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "application.h"
#include "font-enum.h"
#include "font-manager.h"
#include "linked-list-shape.h"
#include "text-input.h"

std::vector<sf::Drawable *> Application::drawables;
std::list<int> Application::list;

void Application::add(sf::Drawable *drawable) { drawables.push_back(drawable); }

void Application::run() {
    list.push_back(1);

    auto listShape =
        LinkedListShape<int>(list, {150, 50}, FontManager::getFont(UBUNTU_R));
    listShape.setFillColor(sf::Color::White, sf::Color::Green,
                           sf::Color(224, 120, 22));

    auto input = TextInput();
    input.setPosition({0, 100});
    input.setSubmitBehavior([&input]() {
        try {
            list.push_back(std::stoi(input.getString().toAnsiString()));
            std::cout << list.back() << std::endl;
        } catch (const std::invalid_argument &e) {
            std::cerr << "Invalid input" << std::endl;
        }
    });

    sf::RenderWindow window({SCREEN_WIDTH, SCREEN_HEIGHT}, "Window");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            input.eventHandler(window, event);
        }
        window.clear();
        window.draw(listShape);
        window.draw(input);
        window.display();
    }
}
