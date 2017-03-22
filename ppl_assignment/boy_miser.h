#ifndef _boy_miser_h
#define _boy_miser_h
#include <string>
using namespace std;

class Miser_boy {
	
	public:
		string name;
		
		int attractiveness;
		
		int intelligence;

		int budget;
		
		int min_attraction_of_girl;

		bool is_committed;
		
		Miser_boy();

		Miser_boy(string, int, int, int, int);

};

#endif
