#include "Dice.h"
#include <cstdlib>
#include <time.h>

Dice::Dice()
{
	this->value = 1;
}
void Dice::diceroll(sf::Sprite d1, sf::RenderWindow& window)
{
	bool x = false;
	do
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			sf::FloatRect bounds = d1.getGlobalBounds();
			if (bounds.contains(mouse))
			{
				srand(time(0));
				value = (rand() % 6) + 1;
				x = true;
			}
		}
	} while (x == false);

}
int Dice::getval()
{
	return this->value;
}