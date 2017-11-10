#ifndef __JOB_H_GARD__
#define __JOB_H_GARD__

#include <iostream>
#include <vector>

using namespace std;

class Job
{
private :
	int id;
	vector<int> sequence;

public:
	Job(int id);
	~Job();
	void add_operation(int id_op);
};

#endif
