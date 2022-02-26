#include "DataBar.hpp"

DataBar::DataBar(float height, bool active) 
{
    this->height = height;
    this->setSize(sf::Vector2<float>(5, height));
    this->setRotation(180);
    if (active) this->setFillColor(deactive_color);
    else this->setFillColor(sf::Color(100, 100, 100));
}

DataBar::DataBar(float height, sf::Color color, bool active) 
{
    this->height = height;
    this->setSize(sf::Vector2<float>(5.f, height));
    this->setRotation(180);
    this->deactive_color = color;
    if(active) this->setFillColor(sf::Color(255, 0, 0));
    else this->setFillColor(color);
}

int DataBar::getHeight() 
{
    return this->height;
}

void DataBar::setActive(bool active)
{
    if (active) this->setFillColor(ACTIVE_COLOR);
    else this->setFillColor(this->deactive_color);
}

std::ostream& operator<<(std::ostream& os, DataBar & db)
{
    os << db.getHeight();
    return os;
}