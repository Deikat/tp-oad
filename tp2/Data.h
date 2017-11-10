#ifndef __DATA_H_GARD__
#define __DATA_H_GARD__

#include <iostream>
#include <vector>

#include "Operation.h"
#include "Job.h"

using namespace std;

class Data
{
private:
	string name;
	int nb_jobs;
	int nb_machines;
	vector<Operation> operations;
	vector<Job> jobs;

public:
	Data(const char * filename);
	~Data();
	string get_name() const;
	int get_nb_jobs() const;
	int get_nb_machines() const;
	Operation& get_operation(int id_op);
	string to_string();
};

#endif
