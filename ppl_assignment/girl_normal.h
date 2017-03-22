#ifndef _girl_normal_h
#define _girl_normal_h
#include <string>
using namespace std;
/* "ifndef" checks if _girl_normal_h is already defined */

class Normal_girl {
	
	public:
		string name;
		
		int attractiveness;
		
		int maintenance;
		
		int intelligence;
		
		int selection_criteria;
		/* selection_criteria = 1 - most attractive boy,
		2 - richest boy and 3 - most intelligent boy */

		bool is_committed;

		Normal_girl();

		Normal_girl(string, int, int, int, int);
		/* Constructor for Normal Girl class */

};

#endif
