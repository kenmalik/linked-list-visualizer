#ifndef LINKED_LIST_APPLICATION
#define LINKED_LIST_APPLICATION

#include <SFML/Graphics/Drawable.hpp>
#include <list>
#include <vector>

class Application {
  public:
    static void run();
    static void add(sf::Drawable *drawable);

  private:
    static constexpr int SCREEN_WIDTH = 1280;
    static constexpr int SCREEN_HEIGHT = 720;

    static std::vector<sf::Drawable *> drawables;
    static std::list<int> list;
};

#endif // !LINKED_LIST_APPLICATION
