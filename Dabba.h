#pragma once
#include <iostream>
#include "Utility.h"
#include <array>
#include <vector>

using namespace std;

class Dabba
{
	array<int, 4> home{};
	array<int, 19>region{};
	vector<int>safespot{};
	color clr;
	int count = 0;
public:
	Dabba(color c);
	int getgoti(int i);
	void setgoti(int val, int ind);
	int gethomegoti(int index);
	void sethomegoti(int val, int ind);
	int safeind(int t);
	int getsafe(int ind);
	void setsafe(int val);
	void popsafe(int ind);
	int getsafesize();
	void setcount();
	int getcount();
};