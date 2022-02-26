#include "utils/sleep.hpp"

void sleep(int milSecs)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milSecs));
}