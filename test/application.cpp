#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "application.h"
#include "button.h"
#include "font-enum.h"
#include "font-manager.h"
#include "linked-list-shape.h"
#include "state-enum.h"
#include "text-input.h"
#include "word.h"

std::vector<sf::Drawable *> Application::drawables;
std::list<int> Application::list;

void Application::add(sf::Drawable *drawable) { drawables.push_back(drawable); }

void Application::run() {
    std::map<int, std::string> pushTypes = {{0, "Changing from back"},
                                            {1, "Changing from front"},
                                            {2, "Changing from selected"}};
    int pushType = 0;

    bool pushingToFront = false;

    auto listShape =
        LinkedListShape<int>(&list, {150, 50}, FontManager::getFont(UBUNTU_R));
    listShape.setPosition(32, 32);

    std::list<int>::iterator iter = list.begin();
    int selector = -1;

    Word indicator;
    indicator.setText("Changing from back");
    indicator.setPosition(listShape.getPosition().x,
                          listShape.getPosition().y + 100);
    indicator.setCharacterSize(24);

    auto popButton = Button(UBUNTU_R);
    popButton.setText("Pop");
    popButton.setTextSize(16);
    popButton.setPosition({indicator.getGlobalBounds().left,
                           indicator.getGlobalBounds().top +
                               indicator.getGlobalBounds().height + 16});
    popButton.setSubmitBehavior([&listShape, &pushType, &iter]() {
        if (!list.empty()) {
            std::cout << "Popping back" << std::endl;
            switch (pushType) {
            case 0:
                list.pop_back();
                break;
            case 1:
                list.pop_front();
                break;
            }
            listShape.update();
        } else {
            std::cerr << "List is empty" << std::endl;
        }
    });

    auto toggleButton = Button(UBUNTU_R);
    toggleButton.setText("Toggle Direction");
    toggleButton.setTextSize(16);
    toggleButton.setPosition({popButton.getGlobalBounds().left +
                                  popButton.getGlobalBounds().width + 16,
                              popButton.getGlobalBounds().top});
    toggleButton.setSubmitBehavior([&pushType, &pushTypes, &indicator, &iter,
                                    &listShape, &selector, &popButton]() {
        pushType++;
        if (pushType > 2) {
            pushType = 0;
        }
        indicator.setText(pushTypes[pushType]);
        if (pushType == 2) {
            popButton.enableState(DISABLED);
            iter = list.begin();
            selector = -1;
            if (list.size() > 0) {
                selector = 0;
                std::cout << "Set iter to " << *iter << std::endl;
            }
        } else {
            popButton.disableState(DISABLED);
            listShape.resetColors();
        }
    });

    Word pushLabel;
    pushLabel.setText("Push: ");
    pushLabel.setPosition({popButton.getGlobalBounds().left,
                           popButton.getGlobalBounds().top +
                               popButton.getGlobalBounds().height + 16});
    pushLabel.setCharacterSize(24);

    auto pushInput = TextInput();
    pushInput.setPosition({pushLabel.getGlobalBounds().left + 110,
                           pushLabel.getGlobalBounds().top});
    pushInput.setSubmitBehavior(
        [&pushInput, &listShape, &pushType, &selector, &iter]() {
            try {
                const int inputNum =
                    std::stoi(pushInput.getString().toAnsiString());
                std::cout << "Pushing " << inputNum << std::endl;
                bool wasEmpty = list.empty();
                switch (pushType) {
                case 0:
                    list.push_back(inputNum);
                    break;
                case 1:
                    list.push_front(inputNum);
                    break;
                case 2:
                    list.insert(iter, inputNum);
                    iter = list.begin();
                    selector = 0;
                    break;
                }
                if (wasEmpty) {
                    std::cout << "Setting iter" << std::endl;
                    selector = 0;
                    iter = list.begin();
                }
                std::cout << "Iter on " << *iter << std::endl;
                listShape.update();
            } catch (const std::invalid_argument &e) {
                std::cerr << "Invalid input" << std::endl;
            }
            pushInput.setString("");
        });
    pushLabel.setPosition(pushLabel.getPosition().x,
                          pushLabel.getPosition().y +
                              (pushInput.getGlobalBounds().height -
                               pushLabel.getGlobalBounds().height) /
                                  2);

    Word removeLabel;
    removeLabel.setText("Remove: ");
    removeLabel.setPosition({pushLabel.getGlobalBounds().left,
                             pushInput.getGlobalBounds().top +
                                 pushInput.getGlobalBounds().height + 16});
    removeLabel.setCharacterSize(24);

    auto removeInput = TextInput();
    removeInput.setPosition({removeLabel.getGlobalBounds().left + 110,
                             removeLabel.getGlobalBounds().top});
    removeInput.setSubmitBehavior([&removeInput, &listShape]() {
        try {
            const int inputNum =
                std::stoi(removeInput.getString().toAnsiString());
            if (!list.empty()) {
                std::cout << "Removing " << inputNum << std::endl;
                list.remove(inputNum);
                listShape.update();
            } else {
                std::cerr << "List is empty" << std::endl;
            }
        } catch (const std::invalid_argument &e) {
            std::cerr << "Invalid input" << std::endl;
        }
        removeInput.setString("");
    });
    removeLabel.setPosition(removeLabel.getPosition().x,
                            removeLabel.getPosition().y +
                                (removeInput.getGlobalBounds().height -
                                 removeLabel.getGlobalBounds().height) /
                                    2);

    sf::RenderWindow window({SCREEN_WIDTH, SCREEN_HEIGHT}, "Window");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (list.size() > 0 && event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right &&
                    selector < list.size() - 1) {
                    selector++;
                    iter++;
                    std::cout << "On " << *iter << std::endl;
                } else if (event.key.code == sf::Keyboard::Left &&
                           selector > 0) {
                    selector--;
                    iter--;
                    std::cout << "On " << *iter << std::endl;
                }
            }
            pushInput.eventHandler(window, event);
            removeInput.eventHandler(window, event);
            popButton.eventHandler(window, event);
            toggleButton.eventHandler(window, event);
        }

        pushInput.update();
        removeInput.update();
        popButton.update();
        toggleButton.update();
        if (pushType == 2 && list.size() != 0 && selector >= 0 &&
            selector < list.size()) {
            listShape.highlight(selector);
        }

        window.clear(sf::Color::White);

        window.draw(indicator);
        window.draw(listShape);
        window.draw(pushInput);
        window.draw(popButton);
        window.draw(toggleButton);
        window.draw(removeLabel);
        window.draw(removeInput);
        window.draw(pushLabel);

        window.display();
    }
}
