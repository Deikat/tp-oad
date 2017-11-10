#include <iostream>
#include <string>
#include <fstream>

#include "Data.h"
#include "Job.h"
#include "Operation.h"

using namespace std;


int main(int argc, char * argv[])
{
	Data data("data/INSTANCES/la01.dat");
	cout << data.to_string() << endl;

	return 0;
}
