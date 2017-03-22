#include <bits/stdc++.h>
#include "girl_choosy.h"
#include "girl_normal.h"
#include "girl_desperate.h"
#include "boy_miser.h"
#include "boy_generous.h"
#include "boy_geek.h"
#include "gift_essential.h"
#include "gift_luxury.h"
#include "gift_utility.h"
#include "couple.h"
#include "additional_functions.h"
#include "additional_functions_2.h"
using namespace std;

int main()
{
	
	generate_input_2();
	
	Choosy_girl g1[50];
	Normal_girl g2[50];
	Desperate_girl g3[50];
	
	Miser_boy b1[100];
	Generous_boy b2[100];
	Geek_boy b3[100];
	
	Essential_gift gt1[250];
	Luxury_gift gt2[250];
	Utility_gift gt3[250];
	Couple c[50];
	int couple_count;

	read_pairup_and_gift(g1,g2,g3,b1,b2,b3,gt1,gt2,gt3,c,&couple_count);

	print_k_happiest(c,couple_count);

	print_k_most_compatible(c,couple_count);
	
	return 0;
}
