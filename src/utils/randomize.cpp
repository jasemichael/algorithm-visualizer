#include "utils/randomize.hpp"
#include "DataBar.hpp"

void randomize(std::vector<DataBar *>& a)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(a.begin(), a.end(), std::default_random_engine(seed));
}