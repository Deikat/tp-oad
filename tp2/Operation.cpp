#include "Operation.h"

Operation::Operation(int id, int id_job, int id_machine, int duree, int position_sequence)
	: id(id), id_job(id_job), id_machine(id_machine), duree(duree), position_sequence(position_sequence)
{
}

Operation::~Operation()
{
}

int Operation::get_id_machine()
{
	return id_machine;
}

int Operation::get_duree()
{
	return duree;
}
