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
				job.add_operation(id_machine);

				id_op++;
			}
			jobs.push_back(job);
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

Operation& Data::get_op_from_jid(int jid)
{
	for (Operation& op : operations)
	{
		if (op.get_jid() == jid)
		{
			return op;
		}
	}
}

Operation& Data::get_op_from_mid(int mid)
{
	for (Operation& op : operations)
	{
		if (op.get_mid() == mid)
		{
			return op;
		}
	}
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
			ss << " " << op.get_mid() << " " << op.get_duree();
			id_op++;
		}
	}

	return ss.str();
}

int Data::evaluer(vector<int> v_bierwirth, vector<Operation>& chemin_critique)
{
	int makespan = 0;

	vector<int> nb_op_job;
	for (int i = 0; i < nb_jobs; i++)
	{
		nb_op_job.push_back(0);
	}

	vector<int> last_op_mach;
	for (int i = 0; i < nb_machines; i++)
	{
		last_op_mach.push_back(-1);
	}

	Operation& last_op = operations[0];
	for (int i = 0; i < (signed) v_bierwirth.size(); i++)
	{
		int jid = v_bierwirth[i];

		int sid = nb_op_job[jid];
		int oid = jobs[jid].get_sequence(sid);
		Operation op = operations[oid];

		int prev_jid = (sid == 0) ? -1 : jobs[jid].get_sequence(sid - 1);
		int stop_prev_jid = (prev_jid == -1) ? 0 : get_op_from_jid(prev_jid).get_duree();

		int prev_mid = last_op_mach[op.get_mid()];
		int stop_prev_mid = (prev_mid == -1) ? 0 : get_op_from_mid(prev_mid).get_duree();

		op.index = i;
		op.start = (stop_prev_jid > stop_prev_mid) ? stop_prev_jid : stop_prev_mid;
		op.end = op.start + op.get_duree();

		if (op.end > makespan)
		{
			makespan = op.end;
			last_op = op;
		}

		op.prev = (op.start == stop_prev_jid) ? prev_jid : prev_mid;
		++nb_op_job[jid];
		last_op_mach[op.get_mid()] = oid;
	}

	while (last_op.prev != -1)
	{
		chemin_critique.push_back(last_op);
		last_op = operations[last_op.prev];
	}

	return makespan;
}

vector<int> Data::recherche_locale(vector<int> v_bierwirth, int n_max)
{
	vector<Operation> chemin_critique;
	int makespan = evaluer(v_bierwirth, chemin_critique);

	int n = 0;
	int i = 0;
	int j = 1;

	while (j < (signed) chemin_critique.size()-1 && n < n_max)
	{
		// si on est sur un arc disjonctif
		if (chemin_critique[i].get_jid() != chemin_critique[j].get_jid())
		{
			vector<int> v_bis = v_bierwirth;

			Operation& op_i = chemin_critique[i];
			Operation& op_j = chemin_critique[j];

			int tmp = v_bierwirth[op_i.index];
			v_bierwirth[op_i.index] = v_bis[op_j.index];
			v_bis[op_j.index] = tmp;

			vector<Operation> chemin_critique_bis;
			int makespan_bis = evaluer(v_bis, chemin_critique_bis);

			if (makespan_bis < makespan)
			{
				i = 0;
				j = 1;
				v_bierwirth = v_bis;
				chemin_critique = chemin_critique_bis;
			}
			else
			{
				i = j++;
			}
		}
		else
		{
			i = j++;
		}
		n++;
	}

	return v_bierwirth;
}
