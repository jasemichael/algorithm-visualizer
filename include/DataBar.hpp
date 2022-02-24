#ifndef DATABAR_HPP_
#define DATABAR_HPP_

#include <SFML/Graphics.hpp>

class DataBar: public sf::RectangleShape {
    
    public:
        DataBar(float height);
        DataBar(float height, sf::Color color);
};
#endif 