#include "namemangling-lib.h"

double foo(int i)
{
    return i*5.5;
}

double foo(double d)
{
    return d*5.5;
}


point::point(int x, int y)
: _x(x), _y(y) {}

void point::move(point vec)
{
    _x += vec._x;
    _y += vec._y;
}
