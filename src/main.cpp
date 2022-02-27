#include <SFML/Graphics.hpp>
#include "DataBar.hpp"
#include "utils/randomize.hpp"
#include "algorithms/bubbleSort.hpp"
#include <iostream>
#include <vector>
#include <filesystem>
#include <thread>

int main() {
    const int WIDTH = 800;
    const int HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Algorithm Visualizer");
    auto icon = sf::Image();

    if (!icon.loadFromFile("assets/sorting.jpeg"))
    {
        // Error handling...
        std::cout << "Couldn't load image" << std::endl;
    } else {
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }
    std::vector<DataBar *> dataBars;
    for(int i=0; i<100; i++) {
        DataBar *db = new DataBar(i+10, false);
        dataBars.push_back(db);
    }
    randomize(dataBars);
    window.clear();
    for(int i=0; i<dataBars.size(); i++)
    {
        dataBars[i]->setPosition((i*6) + (WIDTH/2) - (50*6), HEIGHT/2);
        window.draw(*dataBars[i]);
    }

    std::thread first(bubbleSort, &dataBars, &window);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    first.join();
    return 0;
}