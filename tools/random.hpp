//---------------------------------------------------------------------------------------
#ifndef RANDOM_HPP
#define RANDOM_HPP
//---------------------------------------------------------------------------------------
#include <ctime>
#include <random>
//---------------------------------------------------------------------------------------
namespace tools
{
//---------------------------------------------------------------------------------------
float random( float from, float to )
{
    static std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<> dist(from, to);
    return dist(gen);
}
//---------------------------------------------------------------------------------------
} //tools
//---------------------------------------------------------------------------------------
#endif //RANDOM_HPP
//---------------------------------------------------------------------------------------