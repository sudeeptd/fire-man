#include <bits/stdc++.h>
#include "girl_choosy.h"
#include "boy_geek.h"
using namespace std;
int main()
{
	Choosy_girl g("rekha",1,2,3,4);
	cout<<g.name<<g.is_committed<<endl;
	Geek_boy b;
	b.name = "Hello";
	b.budget = 25;
	cout<<b.name<<" "<<b.budget;
	return 0;

}
