#include "Utility.h"
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void SetClr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}

void init(color**& c, bool**& x, int**& i)
{
	//RED
	//HOME
	c[2][2] = RED;
	x[2][2] = true;
	i[2][2] = 0;
	c[2][4] = RED;
	x[2][4] = true;
	i[2][4] = 1;
	c[4][2] = RED;
	x[4][2] = true;
	i[4][2] = 2;
	c[4][4] = RED;
	x[4][4] = true;
	i[4][4] = 3;
	//REGION
	c[8][5] = RED;
	x[8][5] = false;
	i[8][5] = 0;
	c[8][4] = RED;
	x[8][4] = false;
	i[8][4] = 1;
	c[8][3] = RED;
	x[8][3] = false;
	i[8][3] = 2;
	c[8][2] = RED;
	x[8][2] = false;
	i[8][2] = 3;
	c[8][1] = RED;
	x[8][1] = false;
	i[8][1] = 4;
	c[8][0] = RED;
	x[8][0] = false;
	i[8][0] = 5;

	c[7][0] = RED;
	x[7][0] = false;
	i[7][0] = 6;
	c[7][1] = RED;
	x[7][1] = false;
	i[7][1] = 7;
	c[7][2] = RED;
	x[7][2] = false;
	i[7][2] = 8;
	c[7][3] = RED;
	x[7][3] = false;
	i[7][3] = 9;
	c[7][4] = RED;
	x[7][4] = false;
	i[7][4] = 10;
	c[7][5] = RED;
	x[7][5] = false;
	i[7][5] = 11;

	c[6][0] = RED;
	x[6][0] = false;
	i[6][0] = 13;
	c[6][1] = RED;
	x[6][1] = false;
	i[6][1] = 14;
	c[6][2] = RED;
	x[6][2] = false;
	i[6][2] = 15;
	c[6][3] = RED;
	x[6][3] = false;
	i[6][3] = 16;
	c[6][4] = RED;
	x[6][4] = false;
	i[6][4] = 17;
	c[6][5] = RED;
	x[6][5] = false;
	i[6][5] = 18;


	//BLUE
	//HOME
	c[11][2] = BLUE;
	x[11][2] = true;
	i[11][2] = 0;
	c[11][4] = BLUE;
	x[11][4] = true;
	i[11][4] = 1;
	c[13][2] = BLUE;
	x[13][2] = true;
	i[13][2] = 2;
	c[13][4] = BLUE;
	x[13][4] = true;
	i[13][4] = 3;

	//REGION
	c[9][8] = BLUE;
	x[9][8] = false;
	i[9][8] = 0;
	c[10][8] = BLUE;
	x[10][8] = false;
	i[10][8] = 1;
	c[11][8] = BLUE;
	x[11][8] = false;
	i[11][8] = 2;
	c[12][8] = BLUE;
	x[12][8] = false;
	i[12][8] = 3;
	c[13][8] = BLUE;
	x[13][8] = false;
	i[13][8] = 4;
	c[14][8] = BLUE;
	x[14][8] = false;
	i[14][8] = 5;

	c[9][7] = BLUE;
	x[9][7] = false;
	i[9][7] = 11;
	c[10][7] = BLUE;
	x[10][7] = false;
	i[10][7] = 10;
	c[11][7] = BLUE;
	x[11][7] = false;
	i[11][7] = 9;
	c[12][7] = BLUE;
	x[12][7] = false;
	i[12][7] = 8;
	c[13][7] = BLUE;
	x[13][7] = false;
	i[13][7] = 7;
	c[14][7] = BLUE;
	x[14][7] = false;
	i[14][7] = 6;

	c[9][6] = BLUE;
	x[9][6] = false;
	i[9][6] = 18;
	c[10][6] = BLUE;
	x[10][6] = false;
	i[10][6] = 17;
	c[11][6] = BLUE;
	x[11][6] = false;
	i[11][6] = 16;
	c[12][6] = BLUE;
	x[12][6] = false;
	i[12][6] = 15;
	c[13][6] = BLUE;
	x[13][6] = false;
	i[13][6] = 14;
	c[14][6] = BLUE;
	x[14][6] = false;
	i[14][6] = 13;

	//YELLOW
	//HOME
	c[11][11] = YELLOW;
	x[11][11] = true;
	i[11][11] = 0;
	c[11][13] = YELLOW;
	x[11][13] = true;
	i[11][13] = 1;
	c[13][11] = YELLOW;
	x[13][11] = true;
	i[13][11] = 2;
	c[13][13] = YELLOW;
	x[13][13] = true;
	i[13][13] = 3;
	//REGION
	c[6][9] = YELLOW;
	x[6][9] = false;
	i[6][9] = 0;
	c[6][10] = YELLOW;
	x[6][10] = false;
	i[6][10] = 1;
	c[6][11] = YELLOW;
	x[6][11] = false;
	i[6][11] = 2;
	c[6][12] = YELLOW;
	x[6][12] = false;
	i[6][12] = 3;
	c[6][13] = YELLOW;
	x[6][13] = false;
	i[6][13] = 4;
	c[6][14] = YELLOW;
	x[6][14] = false;
	i[6][14] = 5;

	c[7][9] = YELLOW;
	x[7][9] = false;
	i[7][9] = 11;
	c[7][10] = YELLOW;
	x[7][10] = false;
	i[7][10] = 10;
	c[7][11] = YELLOW;
	x[7][11] = false;
	i[7][11] = 9;
	c[7][12] = YELLOW;
	x[7][12] = false;
	i[7][12] = 8;
	c[7][13] = YELLOW;
	x[7][13] = false;
	i[7][13] = 7;
	c[7][14] = YELLOW;
	x[7][14] = false;
	i[7][14] = 6;

	c[8][9] = YELLOW;
	x[8][9] = false;
	i[8][9] = 18;
	c[8][10] = YELLOW;
	x[8][10] = false;
	i[8][10] = 17;
	c[8][11] = YELLOW;
	x[8][11] = false;
	i[8][11] = 16;
	c[8][12] = YELLOW;
	x[8][12] = false;
	i[8][12] = 15;
	c[8][13] = YELLOW;
	x[8][13] = false;
	i[8][13] = 14;
	c[8][14] = YELLOW;
	x[8][14] = false;
	i[8][14] = 13;

	//GREEN
	//HOME
	c[2][11] = GREEN;
	x[2][11] = true;
	i[2][11] = 0;
	c[2][13] = GREEN;
	x[2][13] = true;
	i[2][13] = 1;
	c[4][11] = GREEN;
	x[4][11] = true;
	i[4][11] = 2;
	c[4][13] = GREEN;
	x[4][13] = true;
	i[4][13] = 3;

	//REGION
	c[5][6] = GREEN;
	x[5][6] = false;
	i[5][6] = 0;
	c[4][6] = GREEN;
	x[4][6] = false;
	i[4][6] = 1;
	c[3][6] = GREEN;
	x[3][6] = false;
	i[3][6] = 2;
	c[2][6] = GREEN;
	x[2][6] = false;
	i[2][6] = 3;
	c[1][6] = GREEN;
	x[1][6] = false;
	i[1][6] = 4;
	c[0][6] = GREEN;
	x[0][6] = false;
	i[0][6] = 5;

	c[5][7] = GREEN;
	x[5][7] = false;
	i[5][7] = 11;
	c[4][7] = GREEN;
	x[4][7] = false;
	i[4][7] = 10;
	c[3][7] = GREEN;
	x[3][7] = false;
	i[3][7] = 9;
	c[2][7] = GREEN;
	x[2][7] = false;
	i[2][7] = 8;
	c[1][7] = GREEN;
	x[1][7] = false;
	i[1][7] = 7;
	c[0][7] = GREEN;
	x[0][7] = false;
	i[0][7] = 6;

	c[5][8] = GREEN;
	x[5][8] = false;
	i[5][8] = 18;
	c[4][8] = GREEN;
	x[4][8] = false;
	i[4][8] = 17;
	c[3][8] = GREEN;
	x[3][8] = false;
	i[3][8] = 16;
	c[2][8] = GREEN;
	x[2][8] = false;
	i[2][8] = 15;
	c[1][8] = GREEN;
	x[1][8] = false;
	i[1][8] = 14;
	c[0][8] = GREEN;
	x[0][8] = false;
	i[0][8] = 13;
}
int convert_clr(color c)
{
	return c;
}
