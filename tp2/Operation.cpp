#include "Operation.h"
#include <sstream>

Operation::Operation(int id, int id_job, int id_machine, int duree, int seq_pos)
	: id(id), id_job(id_job), id_machine(id_machine), duree(duree), seq_pos(seq_pos)
{
}

Operation::~Operation()
{
}

int Operation::get_jid()
{
	return id_job;
}

int Operation::get_mid()
{
	return id_machine;
}

int Operation::get_duree()
{
	return duree;
}

void Operation::set_seq_pos(int new_seq_pos)
{
	seq_pos = new_seq_pos;
}

string Operation::to_string()
{
	stringstream ss;

	ss << "Operation<";
	ss << "id=" << id << " ";
	ss << "id_job=" << id_job << " ";
	ss << "id_machine=" << id_machine << " ";
	ss << "duree=" << duree << " ";
	ss << "seq_pos=" << seq_pos << ">";

	return ss.str();
}
