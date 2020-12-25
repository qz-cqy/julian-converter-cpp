#include "color.h"

static void color(int _COLORS) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _COLORS);}
static void init_color() {color(WHITE);}
static void err_color() {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15|8|128|64);}
static void prt_err(const char *err_msg) {
	err_color();
	printf("[ERROR]");
	color(BR_RED);
	printf(" %s\n", err_msg);
	init_color();
}
