#include <iostream>
#include <string>
#include <fstream>

#include "Data.h"
#include "Job.h"
#include "Operation.h"

using namespace std;


int main(int, char *[])
{
	Data data("data/graphe_exemple.txt");

	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(2);
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);

	cout << data.evaluer(v) << endl;

	return 0;
}
