#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Data.h"
#include "Job.h"
#include "Operation.h"

using namespace std;

int main(int, char *[])
{
	char filename[64];
	for (int i = 1; i < 41; i++)
	{
		sprintf(filename, "data/INSTANCES/la%02d.dat", 3);
		Data data(filename);

		int makespan;
		vector<int> v = data.multistart(1000, &makespan);

		cout << "makespan=" << makespan << " and ";
		cout << "VecteurBierwirth<";
		for (int i : v)
		{
			cout << i << "|";
		}
		cout << ">" << endl;
	}
	return 0;
}
