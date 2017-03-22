#include "boy_miser.h"
#include <string>

Miser_boy::Miser_boy()
{

}

Miser_boy::Miser_boy(string n, int a, int i, int b, int m)
{
	this->name = n;
	this->attractiveness = a;
	this->budget = b;
	this->intelligence = i;
	this->min_attraction_of_girl = m;
	this->is_committed = false;
}
