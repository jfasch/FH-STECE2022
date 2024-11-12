#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void* point_alloc(int x, int y);
void point_free(void* self);
void point_move(void* self, void* vec);
int point_x(void* self);
int point_y(void* self);

#ifdef __cplusplus
}
#endif
