#include <SFML/Graphics.hpp>
#include "DataBar.hpp"
#include "utils/randomize.hpp"
#include <iostream>
#include <vector>
#include <filesystem>

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
    std::vector<int> dataBars;
    for(int i=0; i<100; i++) 
    {
        dataBars.push_back(i+10);
    }
    randomize(dataBars);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for(int i=0; i<100; i++)
        {
            DataBar dataBar(dataBars[i]);
            dataBar.setPosition((i*6) + (WIDTH/2) - (50*6), HEIGHT/2);
            window.draw(dataBar);
        }
        window.display();
    }

    return 0;
}