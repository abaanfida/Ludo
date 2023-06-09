#pragma once
#include <SFML/Graphics.hpp>
class Dice
{
	int value;
public:
	Dice();
	void diceroll(sf::Sprite d1, sf::RenderWindow& window);
	int getval();
};
