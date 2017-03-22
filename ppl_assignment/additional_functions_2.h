#ifndef _additional_functions_2_h
#define _additional_functions_2_h
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

class Input_and_pairup_and_gifting {
	friend void generate_input_2();
	friend void read_pairup_and_gift(Choosy_girl g1[50],
									Normal_girl g2[50],
									Desperate_girl g3[50],
									Miser_boy b1[100],
									Generous_boy b2[100],
									Geek_boy b3[100],
									Essential_gift gt1[250],
									Luxury_gift gt2[250],
									Utility_gift gt3[250],
									Couple c[50],
									int *couple_count);
	friend int give_gifts(int b_type, int g_type, string b_name, string g_name, Essential_gift gt1[250],
							Luxury_gift gt2[250], Utility_gift gt3[250],
							Couple c[50], int maintenance, int budget, int c_cnt,
							int cnt_gt1, int cnt_gt2, int cnt_gt3, int intel);
	
};

void generate_input_2();
void read_pairup_and_gift(Choosy_girl g1[50],
									Normal_girl g2[50],
									Desperate_girl g3[50],
									Miser_boy b1[100],
									Generous_boy b2[100],
									Geek_boy b3[100],
									Essential_gift gt1[250],
									Luxury_gift gt2[250],
									Utility_gift gt3[250],
									Couple c[50],
									int *couple_count);
int give_gifts(int b_type, int g_type, string b_name, string g_name, Essential_gift gt1[250],
							Luxury_gift gt2[250], Utility_gift gt3[250],
							Couple c[50], int maintenance, int budget, int c_cnt,
							int cnt_gt1, int cnt_gt2, int cnt_gt3, int intel);

#endif
