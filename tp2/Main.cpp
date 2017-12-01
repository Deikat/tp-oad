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
	Data data("data/graphe_exemple.txt");

	vector<int> v_bierwirth;
	v_bierwirth.push_back(1);
	v_bierwirth.push_back(0);
	v_bierwirth.push_back(0);
	v_bierwirth.push_back(0);
	v_bierwirth.push_back(2);
	v_bierwirth.push_back(1);
	v_bierwirth.push_back(1);
	v_bierwirth.push_back(2);
	v_bierwirth.push_back(2);

	vector<Operation> chemin_critique;
	data.evaluer(v_bierwirth, chemin_critique);

	cout << "VecteurBierwirth<";
	for (int i : v_bierwirth)
	{
		cout << i << "|";
	}
	cout << ">" << endl;

	return 0;
}
