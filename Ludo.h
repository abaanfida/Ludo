#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.h"
#include "Dice.h"
#include <vector>
using namespace std;

class Ludo
{
	Board* b;
	Dice* D;
	vector<int> moves;
	int** positions;
	color** C;
	bool** ishomes;
	int turn;
	int si, di;
	int pri, pci;
	color w_clr;
public:
	Ludo();
	void play();
	void turnchange();
	void six_handling(sf::RenderWindow& window, sf::Sprite& D, sf::Sprite& D1, sf::Sprite& D2, sf::Sprite& D3, sf::Sprite& D4, sf::Sprite& D5, sf::Sprite& D6, sf::Text turn_msg);
	void moves_display(sf::RenderWindow& window, sf::Sprite& D1, sf::Sprite& D2, sf::Sprite& D3, sf::Sprite& D4, sf::Sprite& D5, sf::Sprite& D6);
	void transform(color& c, bool& x, int& i, int ri, int ci);
	void select_piece(sf::RenderWindow& window);
	void move_select(sf::RenderWindow& window, int& ind, int& val, sf::Sprite& D1, sf::Sprite& D2, sf::Sprite& D3, sf::Sprite& D4, sf::Sprite& D5, sf::Sprite& D6);
	bool legal_move(int i, int safei, color clr, bool x, int t, int m);
	void move(sf::RenderWindow& window, sf::Sprite& D, sf::Sprite& D1, sf::Sprite& D2, sf::Sprite& D3, sf::Sprite& D4, sf::Sprite& D5, sf::Sprite& D6, bool& iskill);
	void menu();
};