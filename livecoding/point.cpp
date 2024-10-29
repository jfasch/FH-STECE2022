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

    void print()
    {
        cout << '(' << _x << ',' << _y << ")\n";
    }

private:
    const int _x;
    const int _y;
};

int main()
{
    point p(1, 2);
    point vec(3, 1);
    point moved = p.move(vec);
    cout << "original p: ";
    p.print();
    cout << "moved: ";
    moved.print();

    point p_default;
    p_default.print();

    return 0;
}
