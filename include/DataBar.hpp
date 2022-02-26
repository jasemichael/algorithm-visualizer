#ifndef DATABAR_HPP_
#define DATABAR_HPP_
#include <iostream>
#include <SFML/Graphics.hpp>

class DataBar: public sf::RectangleShape {
    private:
        int height;
        sf::Color const ACTIVE_COLOR = sf::Color(255, 0, 0);
        sf::Color deactive_color = sf::Color(100, 100, 100);
    public:
        DataBar() { };
        DataBar(float height, bool active);
        DataBar(float height, sf::Color color, bool active);
        ~DataBar() {};
        DataBar operator=(const DataBar &);
        friend std::ostream& operator<<(std::ostream& os, DataBar & db);
        int getHeight();
        void setActive(bool active);
};
#endif 