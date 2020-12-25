#ifndef COLOR_H
#define COLOR_H 1

#include <cstdio>
#include <windows.h>
#define COL_GD 1
#define BLACK 0
#define BLUE  1
#define GREEN 2
#define BAD_YANHE 3
#define RED   4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY  8
#define BR_BLUE  9
#define BR_GREEN 10
#define BR_YANHE 11
#define BR_RED   12
#define BR_PURPLE 13
#define BR_YELLOW 14
#define BR_WHITE 15

static void color(int _COLORS);
static void init_color();
static void err_color();
static void prt_err(const char *err_msg);

#endif
