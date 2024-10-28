#include <iostream>
using namespace std;

struct point
{
    int x;
    int y;
};

void point_print(point p)
{
    cout << '(' << p.x << ',' << p.y << ")\n";
}

int main()
{
    point p;
    point_print(p);
    
    return 0;
}
