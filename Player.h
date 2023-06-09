#pragma once
#include <iostream>
#include "Utility.h"
using namespace std;
class Player
{
	string name;
	color clr;
public:
	Player(string n, color c);
	string getname();
	color getcolor();
};
