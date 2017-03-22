#ifndef _boy_generous_h
#define _boy_generous_h
#include <string>
using namespace std;

class Generous_boy {
	
	public:
		string name;
		
		int attractiveness;
		
		int intelligence;

		int budget;
		
		int min_attraction_of_girl;

		bool is_committed;
		
		Generous_boy();

		Generous_boy(string, int, int, int, int);

};

#endif
