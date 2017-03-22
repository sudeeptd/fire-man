#include <bits/stdc++.h>
#include "girl_choosy.h"
#include "girl_normal.h"
#include "girl_desperate.h"
#include "boy_miser.h"
#include "boy_generous.h"
#include "boy_geek.h"
#include "additional_functions.h"
using namespace std;

int main()
{
	
	Choosy_girl g1[50];
	Normal_girl g2[50];
	Desperate_girl g3[50];
	
	Miser_boy b1[100];
	Generous_boy b2[100];
	Geek_boy b3[100];

	vector <pair <string, string> > couples;

	generate_input();

	read_input_and_pair(g1,g2,g3,b1,b2,b3,&couples);

	print_couples(couples);

	return 0;
}