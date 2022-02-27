#include "algorithms/bubbleSort.hpp"
#include "DataBar.hpp"
#include "utils/sleep.hpp"

void bubbleSort(std::vector<DataBar *>* a, sf::RenderWindow* window)
{
    bool done = false;
    while(!done) {
        done = true;
        for(int i=0; i<a->size()-1; i++) {
            a->at(i)->setActive(true);
            sleep(5);
            if(a->at(i)->getHeight() > a->at(i+1)->getHeight()) {
                done = false;
                DataBar* temp = a->at(i+1);
                sf::Vector2f pos1 = a->at(i+1)->getPosition();
                sf::Vector2f pos2 = a->at(i)->getPosition();
                a->at(i)->setPosition(pos1);
                a->at(i+1)->setPosition(pos2);
                a->at(i+1) = a->at(i);
                a->at(i) = temp;
            }
            a->at(i)->setActive(false);
            a->at(i+1)->setActive(false);
        }
    }
}