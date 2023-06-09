#include "Player.h"
#include"Utility.h"
#include <iostream>

Player::Player(string n, color c)
{
	this->name = n;
	this->clr = c;
}
string Player::getname()
{
	return this->name;
}
color Player::getcolor()
{
	return this->clr;
}