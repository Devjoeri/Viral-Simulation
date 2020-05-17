#include <iostream>
#include "regularstrategy.h"

using namespace std;
namespace corsim
{
	bool RegularStrategy::move() {
		cout << "The subject chooses to move" << endl;
		return true;
	}
}