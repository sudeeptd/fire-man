#include "boy_geek.h"
#include <string>

Geek_boy::Geek_boy()
{
	
}
Geek_boy::Geek_boy(string n, int a, int i, int b, int m)
{
	this->name = n;
	this->attractiveness = a;
	this->budget = b;
	this->intelligence = i;
	this->min_attraction_of_girl = m;
	this->is_committed = false;
}
