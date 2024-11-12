#pragma once

double foo(int i);
double foo(double d);

class point
{
public:
    point(int x, int y);
    void move(point vec);

    int x() const { return _x; }
    int y() const { return _y; }

private:
    int _x, _y;
};
