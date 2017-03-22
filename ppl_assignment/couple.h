#ifndef _couple_h
#define _couple_h
#include <string>
using namespace std;

class Couple {
	public:
		string boy_name;

		string girl_name;
		
		long double couple_happiness;
		
		int couple_compatibility;

		int gift_total_price;
		
		void set_couple_happiness(long double);
		
		void set_couple_compatibility(int);

};

#endif