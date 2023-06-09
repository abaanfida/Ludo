#pragma once
#include<windows.h>
#include<conio.h>

enum color { WHITE = 0, BLUE = 1, RED = 2, GREEN = 3, YELLOW = 4 };
void getRowColbyLeftClick(int& rpos, int& cpos);
void gotoRowCol(int rpos, int cpos);
void SetClr(int clr);
void init(color**& c, bool**& x, int**& i);
int convert_clr(color c);
