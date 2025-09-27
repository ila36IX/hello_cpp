#include "Point.h"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
        Fixed w1_up;
        Fixed w1_down;
        Fixed w1;
        Fixed w2;

        w1_up = a.getx() * (c.gety() - a.gety()) + (point.gety() - a.gety()) * (c.getx() - a.getx()) -
                point.getx() * (c.gety() - a.gety());
        w1_down = (b.gety() - a.gety()) * (c.getx() - a.getx()) - (b.getx() - a.getx()) * (c.gety() - a.gety());
        w1      = w1_up / w1_down;
        w2      = (point.gety() - a.gety() - w1 * (b.gety() - a.gety())) / (c.gety() - a.gety());
        // std::cout << "w1 = " << w1 << "\n";
        // std::cout << "w2 = " << w2 << "\n";
        if (w1 > 0 && w2 > 0 && (w1 + w2) < 1)
        {
                return (true);
        }
        else
        {
                return (false);
        }
}
