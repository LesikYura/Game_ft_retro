#ifndef TOOL_H
# define TOOL_H

#define HIGHT 35// y - высота
#define WIDTH 70 // x - ширин
#define SCREEN_HIGHT HIGHT + 3 // y - высота
#define SCREEN_WIDTH WIDTH + 2 // x - ширин
#define FIELD_SIZE HIGHT * WIDTH;
// #define X_START 10
// #define Y_START 10

typedef struct s_xy
{
    int x;
    int y;
}                t_xy;

#endif