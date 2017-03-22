#ifndef _girl_choosy_h
#define _girl_choosy_h
#include <string>
using namespace std;
/* "ifndef" checks if _girl_choosy_h is already defined */

class Choosy_girl {
	
	public:
		string name;
		
		int attractiveness;
		
		int maintenance;
		
		int intelligence;
		
		int selection_criteria;
		/* selection_criteria = 1 - most attractive boy,
		2 - richest boy and 3 - most intelligent boy */

		bool is_committed;

		Choosy_girl();

		Choosy_girl(string, int, int, int, int);
		/* Constructor for Choosy Girl class */

};

#endif
