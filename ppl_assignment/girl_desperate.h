#ifndef _girl_desperate_h
#define _girl_desperate_h
#include <string>
using namespace std;
/* "ifndef" checks if _girl_desperate_h is already defined */

class Desperate_girl {
	
	public:
		string name;
		
		int attractiveness;
		
		int maintenance;
		
		int intelligence;
		
		int selection_criteria;
		/* selection_criteria = 1 - most attractive boy,
		2 - richest boy and 3 - most intelligent boy */

		bool is_committed;

		Desperate_girl();
		
		Desperate_girl(string, int, int, int, int);
		/* Constructor for Desperate Girl class */

};

#endif