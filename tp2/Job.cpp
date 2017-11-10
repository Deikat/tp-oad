#include "Job.h"

Job::Job(int id) : id(id)
{
}

Job::~Job()
{
}

void Job::add_operation(int id_op)
{
	sequence.push_back(id_op);
}
