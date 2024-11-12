#include <iostream>
using namespace std;

// struct Gyro
// {
//     int fd;
// };

class point
{
public:
    point()
    : _x(0), _y(0) // initializer list
    {}

    point(int x, int y)
    : _x(x), _y(y) // initializer list
    {}

    point move(point vec)
    {
        int x = _x + vec._x;
        int y = _y + vec._y;
        return point(x, y); // temporary object
    }

    point& operator+=(point vec)
    {
        _x += vec._x;
        _y += vec._y;
        return *this;
    }

    void print()
    {
        cout << '(' << _x << ',' << _y << ")\n";
    }

private:
    int _x;
    int _y;
};

int main()
{
    point p = {1, 2};   // "C++11 brace initialization"
    point vec(3, 1);
    point moved = p.move(vec);
    cout << "original p: ";
    p.print();
    cout << "moved: ";
    moved.print();

    point p_default;
    p_default.print();

    point another_point(42, 666);
    another_point += point(30, 20);

    return 0;
}
