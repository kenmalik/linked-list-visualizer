#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "application.h"
#include "button.h"
#include "font-enum.h"
#include "font-manager.h"
#include "linked-list-shape.h"
#include "text-input.h"
#include "word.h"

std::vector<sf::Drawable *> Application::drawables;
std::list<int> Application::list;

void Application::add(sf::Drawable *drawable) { drawables.push_back(drawable); }

void Application::run() {
    bool pushingToFront = false;

    auto listShape =
        LinkedListShape<int>(&list, {150, 50}, FontManager::getFont(UBUNTU_R));
    listShape.setPosition(32, 32);

    Word indicator;
    indicator.setText("Changing from back");
    indicator.setPosition(listShape.getPosition().x,
                          listShape.getPosition().y + 100);
    indicator.setCharacterSize(24);

    auto input = TextInput();
    input.setPosition({indicator.getGlobalBounds().left,
                       indicator.getGlobalBounds().top +
                           indicator.getGlobalBounds().height + 10});
    input.setSubmitBehavior([&input, &listShape, &pushingToFront]() {
        try {
            const int inputNum = std::stoi(input.getString().toAnsiString());
            std::cout << "Pushing " << inputNum << std::endl;
            if (pushingToFront) {
                list.push_front(inputNum);
            } else {
                list.push_back(inputNum);
            }
            listShape.update();
        } catch (const std::invalid_argument &e) {
            std::cerr << "Invalid input" << std::endl;
        }
    });

    auto popBackButton = Button(UBUNTU_R);
    popBackButton.setText("Pop");
    popBackButton.setTextSize(16);
    popBackButton.setPosition(
        {input.getGlobalBounds().left,
         input.getGlobalBounds().top + input.getGlobalBounds().height + 10});
    popBackButton.setSubmitBehavior([&listShape, &pushingToFront]() {
        if (!list.empty()) {
            std::cout << "Popping back" << std::endl;
            if (pushingToFront) {
                list.pop_front();
            } else {
                list.pop_back();
            }
            listShape.update();
        } else {
            std::cerr << "List is empty" << std::endl;
        }
    });

    auto toggleButton = Button(UBUNTU_R);
    toggleButton.setText("Toggle Direction");
    toggleButton.setTextSize(16);
    toggleButton.setPosition({popBackButton.getGlobalBounds().left,
                              popBackButton.getGlobalBounds().top +
                                  popBackButton.getGlobalBounds().height + 10});
    toggleButton.setSubmitBehavior([&pushingToFront, &indicator]() {
        pushingToFront = !pushingToFront;
        indicator.setText(pushingToFront ? "Changing from front"
                                         : "Changing from back");
    });

    sf::RenderWindow window({SCREEN_WIDTH, SCREEN_HEIGHT}, "Window");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            input.eventHandler(window, event);
            popBackButton.eventHandler(window, event);
            toggleButton.eventHandler(window, event);
        }

        input.update();
        popBackButton.update();
        toggleButton.update();

        window.clear(sf::Color::White);

        window.draw(indicator);
        window.draw(listShape);
        window.draw(input);
        window.draw(popBackButton);
        window.draw(toggleButton);

        window.display();
    }
}
