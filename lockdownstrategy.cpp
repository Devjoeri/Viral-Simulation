#include <iostream>
#include "lockdownstrategy.h"

using namespace std;
namespace corsim
{
	bool LockdownStrategy::move() {
		cout << "The subject chooses to not move" << endl;
		return false;
	}
}