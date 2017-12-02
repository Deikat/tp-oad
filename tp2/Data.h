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

	vector<vector<int>> duplicates;

public:
	Data(const char * filename);
	~Data();
	string get_name() const;
	int get_nb_jobs() const;
	int get_nb_machines() const;
	Operation& get_operation(int id_op);
	Operation& get_op_from_jid(int jid);
	Operation& get_op_from_mid(int mid);
	string to_string();

	int evaluer(vector<int> v_bierwirth, vector<Operation>& chemin_critique);
	vector<int> recherche_locale(vector<int> v_bierwirth, int n_max, int * makespan);
	bool tester_double(vector<int> v_bierwirth);
	vector<int> multistart(int n_max, int * makespan);
};

int cmp_bierwirth(vector<int> v1, vector<int> v2);

#endif
