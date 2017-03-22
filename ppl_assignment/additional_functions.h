#ifndef _additional_functions_h
#define _additional_functions_h
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

class Input_and_pairup
{
	friend void generate_input();
	
	friend void read_input_and_pair(Choosy_girl g1[50],
									Normal_girl g2[50],
									Desperate_girl g3[50],
									Miser_boy b1[100],
									Generous_boy b2[100],
									Geek_boy b3[100],
									vector< pair<string, string> > *couples);

	friend void print_k_happiest(Couple c[50], int);
	friend void print_k_most_compatible(Couple c[50], int);
	friend void print_couples(vector< pair<string, string> > couples);
};

void read_input_and_pair(Choosy_girl g1[50],
						Normal_girl g2[50],
						Desperate_girl g3[50],
						Miser_boy b1[100],
						Generous_boy b2[100],
						Geek_boy b3[100],
						vector< pair<string, string> > *couples);

void generate_input();

void print_k_happiest(Couple c[50], int);
void print_k_most_compatible(Couple c[50], int);
void print_couples(vector< pair<string, string> > couples);

#endif
