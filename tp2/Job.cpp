#include "Job.h"
#include <sstream>

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

int Job::get_sequence(int sid)
{
	return sequence[sid];
}

string Job::to_string()
{
	stringstream ss;

	ss << "Job<id=" << id << " seq=|";
	for (int i = 0; i < (signed) sequence.size(); i++)
	{
		ss << sequence[i] << "|";
	}
	ss << ">";

	return ss.str();
}
