#ifndef __OPERATION_H_GARD__
#define __OPERATION_H_GARD__

#include <iostream>
#include <vector>

using namespace std;

class Operation
{
private:
	int id;
	int id_job;
	int id_machine;
	int duree;
	int position_sequence;

public:
	Operation(int id, int id_job, int id_machine, int duree, int position_sequence);
	~Operation();
	int get_id_machine();
	int get_duree();
};

#endif
