#include <iostream>

using namespace std;

class Engine {
public:
	void fire(void) { cout << "fire engine;" << endl; };

	void stall(void) {
		cout << "stall engine" << endl;
	}
};
