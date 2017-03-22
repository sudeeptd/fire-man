#ifndef _boy_geek_h
#define _boy_geek_h
#include <string>
using namespace std;

class Geek_boy {
	
	public:
		string name;
		
		int attractiveness;
		
		int intelligence;

		int budget;
		
		int min_attraction_of_girl;

		bool is_committed;

		Geek_boy();
		
		Geek_boy(string, int, int, int, int);

};

#endif