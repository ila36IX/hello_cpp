#include "Point.h"

int main()
{
        Point a(3, 4), b(8, 6), c(6, 3);

        std::cout << "YES: " << bsp(a, b, c, Point(6.4604f, 4.33f)) << "\n";
        std::cout << "YES: " << bsp(a, b, c, Point(5.9653f, 3.09f)) << "\n";
        std::cout << "YES: " << bsp(a, b, c, Point(3.1049f, 4.01f)) << "\n";
        std::cout << "NO : " << bsp(a, b, c, Point(8.0194f, 5.90f)) << "\n";
        std::cout << "NO : " << bsp(a, b, c, Point(6.2926f, 3.01f)) << "\n";
        std::cout << "NO : " << bsp(a, b, c, Point(3.9111f, 4.42f)) << "\n";
        return (0);
}
