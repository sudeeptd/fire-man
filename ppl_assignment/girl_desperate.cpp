#include "girl_desperate.h"
#include <string>

Desperate_girl::Desperate_girl()
{
	this->is_committed = false;
}

Desperate_girl::Desperate_girl(string n, int a, int m, int i, int s)
{
	this->name = n;
	this->attractiveness = a;
	this->maintenance = m;
	this->intelligence = i;
	this->selection_criteria = s;
	this->is_committed = false;
}
