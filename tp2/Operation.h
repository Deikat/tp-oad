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
	int seq_pos; // ?

public:
	int index;
	int start;
	int end;
	int prev;

	Operation(int id, int id_job, int id_machine, int duree, int seq_pos);
	~Operation();
	int get_jid();
	int get_mid();
	int get_duree();
	void set_seq_pos(int new_seq_pos);
	string to_string();
};

#endif
