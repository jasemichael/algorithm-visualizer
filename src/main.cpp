#include <SFML/Graphics.hpp>
#include "DataBar.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <filesystem>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Algorithm Visualizer");
    auto icon = sf::Image();

    if (!icon.loadFromFile(std::filesystem::current_path().parent_path().parent_path().u8string() + "/assets/sorting.jpeg"))
    {
        // Error handling...
        std::cout << "Couldn't load image" << std::endl;
    } else {
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }
    std::vector<DataBar> dataBars;
    for(int i=0; i<100; i++) 
    {
        DataBar dataBar(i+10);
        dataBar.setPosition(100 + i*6 , 800);
        dataBars.push_back(dataBar);
    }
    unsigned seed = std::chrono::system_clock::now()
        .time_since_epoch()
        .count();
    shuffle(dataBars.begin(), dataBars.end(), std::default_random_engine(seed));
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
            window.draw(dataBars[i]);
        }
        window.display();
    }

    return 0;
}