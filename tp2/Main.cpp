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
	// variable qui prendra la valeur de chacun des noms de fichier des instances
	char filename[64];
	// pour chaque instance
	for (int i = 1; i < 41; i++)
	{
		filename[0] = 0;
		sprintf(filename, "data/INSTANCES/la%02d.dat", i);
		Data data(filename);

		int makespan;
		vector<int> v = data.multistart(1000, &makespan);

		cout << "fichier : " << filename << endl;
		cout << "makespan=" << makespan << endl;
		cout << "vecteur_bierwirth< ";
		for (int i : v)
		{
			cout << i << " ";
		}
		cout << ">" << endl << endl;
	}
	return 0;
}
