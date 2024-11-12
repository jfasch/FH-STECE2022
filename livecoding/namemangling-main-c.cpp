#include "namemangling-lib-c.h"

#include <iostream>


int main()
{
    void* my_point = point_alloc(1, 2);
    void* my_vec = point_alloc(3, 4);

    point_move(my_point, my_vec);

    std::cout << point_x(my_point) << ',' << point_y(my_point) << std::endl;

    point_free(my_point);
    return 0;
}


