#include "namemangling-lib.h"

#include <iostream>


int main()
{
    double d = foo(42); // <-- typeof(42) == int
    std::cout << d << std::endl;

    d = foo(42.666);
    std::cout << d << std::endl;

    point p(1, 2);
    p.move(point(3, 4));

    std::cout << p.x() << ',' << p.y() << std::endl;
    return 0;
}
