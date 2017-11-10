#include <iostream>
#include <fstream>
#include <sstream>

#include "Data.h"

Data::Data(const char * filename)
{
	ifstream f;
	f.open(filename);
	if (f.is_open())
	{
		getline(f, name);
		f >> nb_jobs;
		f >> nb_machines;

		int id_op = 0;
		for (int id_job = 0; id_job < nb_jobs; id_job++)
		{
			Job job(id_job);
			for (int pos = 0; pos < nb_machines; pos++)
			{
				int id_machine, duree;
				f >> id_machine;
				f >> duree;

				operations.push_back(Operation(id_op, id_job, id_machine, duree, pos));
				job.add_operation(id_op);

				id_op++;
			}
		}
	}
}

Data::~Data()
{
}

string Data::get_name() const
{
	return name;
}

int Data::get_nb_jobs() const
{
	return nb_jobs;
}

int Data::get_nb_machines() const
{
	return nb_machines;
}

Operation& Data::get_operation(int id_op)
{
	return operations[id_op];
}

string Data::to_string()
{
	stringstream ss;
	ss << get_name() << endl;
	ss << " " << get_nb_jobs() << " " << get_nb_machines();

	int id_op = 0;
	for (int id_job = 0; id_job < nb_jobs; id_job++)
	{
		ss << endl;
		for (int pos = 0; pos < nb_machines; pos++)
		{
			Operation op = get_operation(id_op);
			ss << " " << op.get_id_machine() << " " << op.get_duree();
			id_op++;
		}
	}

	return ss.str();
}
