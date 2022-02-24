#include "DataBar.hpp"

DataBar::DataBar(float height) {
    this->setSize(sf::Vector2<float>(5, height));
    this->setFillColor(sf::Color(100, 100, 100));
    this->setRotation(180);
}

DataBar::DataBar(float height, sf::Color color) {
    this->setSize(sf::Vector2<float>(5.f, height));
    this->setFillColor(color);
    this->setRotation(180);
}