#include "namemangling-lib-c.h"
#include "namemangling-lib.h"

extern "C" {

void* point_alloc(int x, int y)
{
    return new point(x, y);
}
void point_free(void* self)
{
    point* p = (point*)self;
    delete p;
}
void point_move(void* self, void* vec)
{
    point* self_p = (point*)self;
    point* vec_p = (point*)vec;

    self_p->move(*vec_p);
}
int point_x(void* self)
{
    point* self_p = (point*)self;
    return self_p->x();
}
int point_y(void* self)
{
    point* self_p = (point*)self;
    return self_p->y();
}

}
