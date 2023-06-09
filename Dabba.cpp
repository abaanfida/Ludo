#include "Dabba.h"
#include <vector>
Dabba::Dabba(color c)
{
	this->clr = c;
	for (int i = 0; i < 4; i++)
	{
		this->home[i] = c;
	}
	safespot.push_back(0);
}
int Dabba::gethomegoti(int index)
{
	return this->home[index];
}
int Dabba::getgoti(int index)
{
	return this->region[index];
}
void Dabba::sethomegoti(int val, int ind)
{
	this->home[ind] = val;
}
void Dabba::setgoti(int val, int ind)
{
	this->region[ind] = val;
}
int Dabba::safeind(int t)
{
	for (int i = 0; i < safespot.size(); i++)
	{
		if (safespot[i] == t)
		{
			return i;
		}
	}
}
int Dabba::getsafe(int index)
{
	if (index < 0 || index >= safespot.size())
		return 0;
	return this->safespot[index];
}
void Dabba::setsafe(int val)
{
	this->safespot.push_back(val);
}
void Dabba::popsafe(int ind)
{
	this->safespot.erase(safespot.begin() + ind);
	if (safespot.size() == 0)
	{
		safespot.push_back(0);
	}
}
int Dabba::getsafesize()
{
	return this->safespot.size();
}

void Dabba::setcount()
{
	count++;
}
int Dabba::getcount()
{
	return count;
}


