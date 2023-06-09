#pragma once
#include <SFML/Graphics.hpp>
#include "Dabba.h"
class Board
{
	Dabba* Green;
	Dabba* Blue;
	Dabba* Red;
	Dabba* Yellow;
public:
	Board();
	void display(sf::RenderWindow& window, color** c, int** ind, bool** x);
	void draw_piece(sf::RenderWindow& window, int ri, int ci, int p, float rf, float cf, bool ishome);
	void draw_safe(sf::RenderWindow& window, int ri, int ci, float sp, color clr);
	bool ishfull(color clr);
	void move(int si, int safei, color sclr, bool sh, int val, int t, bool& iskill);
	Dabba* getregion_i(int i);
	Dabba* getregion(color clr);
	void send_back(int i);
};

