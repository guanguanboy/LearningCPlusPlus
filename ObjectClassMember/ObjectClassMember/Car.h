#include "engine.h"

class Car {
public:
	void run() {
		engine.fire();
		cout << "car begin to run" << endl;
	}

	void stop() {
		engine.stall();
		cout << "car stopped" << endl;
	}

private:
	Engine engine;
};