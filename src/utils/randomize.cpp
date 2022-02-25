#include "utils/randomize.hpp"
#include <algorithm>
#include <random>
#include <chrono>

void randomize(std::vector<int>& a) 
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(a.begin(), a.end(), std::default_random_engine(seed));
}