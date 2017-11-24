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

int Data::evaluer(vector<int> v_bierwirth)
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

	for (int i = 0; i < (signed) v_bierwirth.size(); i++)
	{
		cout << "i=" << i << endl;
		int jid = v_bierwirth[i];
		cout << "jid=" << jid << endl;

		int sid = nb_op_job[jid];
		cout << "sid=" << sid << endl;
		cout << jobs[jid].to_string() << endl;
		int oid = jobs[jid].get_sequence(sid);
		cout << "oid=" << oid << endl;
		Operation op = operations[oid];
		cout << "op=" << op.to_string() << endl;

		int prev_jid = (sid == 0) ? -1 : jobs[jid].get_sequence(sid - 1);
		cout << "prev_jid=" << prev_jid << endl;
		int stop_prev_jid = (prev_jid == -1) ? 0 : get_op_from_jid(prev_jid).get_duree();
		cout << "stop_prev_jid=" << stop_prev_jid << endl;

		cout << "last_op_mach=|";
		for (int i : last_op_mach)
		{
			cout << i << "|";
		}
		cout << endl;

		int prev_mid = last_op_mach[op.get_mid()];
		cout << "prev_mid=" << prev_mid << endl;
		int stop_prev_mid = (prev_mid == -1) ? 0 : get_op_from_mid(prev_mid).get_duree();
		cout << "stop_prev_mid=" << stop_prev_mid << endl;

		op.index = i;
		cout << "op.index=" << op.index << endl;
		op.start = (stop_prev_jid > stop_prev_mid) ? stop_prev_jid : stop_prev_mid;
		cout << "op.start=" << op.start << endl;
		op.end = op.start + op.get_duree();
		cout << "op.end=" << op.end << endl;

		if (op.end > makespan)
			makespan = op.end;

		op.prev = (op.start == stop_prev_jid) ? prev_jid : prev_mid;
		cout << "op.prev=" << op.prev << endl;
		++nb_op_job[jid];
		last_op_mach[op.get_mid()] = oid;

		cout << "makespan=" << makespan << endl << endl;
	}

	return makespan;
}
