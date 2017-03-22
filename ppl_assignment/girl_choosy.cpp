#include "girl_choosy.h"
#include <string>

Choosy_girl::Choosy_girl()
{
}

Choosy_girl::Choosy_girl(string n, int a, int m, int i, int s)
{
	this->name = n;
	this->attractiveness = a;
	this->maintenance = m;
	this->intelligence = i;
	this->selection_criteria = s;
	this->is_committed = false;
}
