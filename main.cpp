#include "kauser.h"
#include "kagraph.h"
#include <iostream>
using namespace std;

int main()
{
	kagraph tester1;
	for (int i = 0; i < 11; i++)
	{
		tester1.adduser();
	}
	tester1.addrelation(0,1);
	tester1.addrelation(0,2);
	tester1.addrelation(3,2);
	tester1.addrelation(3,4);
	tester1.addrelation(1,7);
	tester1.addrelation(1,8);
	tester1.addrelation(2,5);
	tester1.addrelation(2,6);
	tester1.addrelation(4,9);
	tester1.total_infection(2);
	tester1.removeuser(4);
	tester1.total_infection(7);
	tester1.limited_infection(2,4);
	for (int j = 0; j < 11; j++)
	{
		if (j != 4)
			cout << "User "<< j << " has version " << ((tester1.database)[j])->ver << endl;
	}
}