#include <iostream>

#include "WMath/Vector2.hpp"


int main(int argc, char* argv[])
{
    WMath::Vector2 in(0, 0);
    WMath::Vector2 out(1, 1);
    for(int i = 0; i < 5; i++)
    {
        float t = static_cast<float>(i) / 4.0f;
        std::cout << "T: " << t << std::endl;
        std::cout << "Lerp: " << WMath::Vector2::Lerp(in, out, t).ToString() << std::endl;
        std::cout << "SLerp: " << WMath::Vector2::Slerp(in, out, t).ToString() << std::endl;
    }
    
    return 0;
}
