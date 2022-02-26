#include "algorithms/bubbleSort.hpp"
#include "DataBar.hpp"
#include "utils/sleep.hpp"

void bubbleSort(std::vector<DataBar *>& a, sf::RenderWindow& window)
{
    bool done = false;
    while(!done) {
        done = true;
        for(int i=0; i<a.size()-1; i++) {
            sleep(10);
            if(a[i]->getHeight() > a[i+1]->getHeight()) {
                done = false;
                DataBar* temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
            }
        }
    }
}