#ifndef __JOB_H_GARD__
#define __JOB_H_GARD__

#include <iostream>
#include <vector>

using namespace std;

class Job
{
public:
	int id;
	vector<int> sequence;

	Job(int id);
	~Job();
	void add_operation(int id_op);
	int get_sequence(int sid);
	string to_string();
};

#endif
