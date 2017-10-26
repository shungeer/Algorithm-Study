// Greedy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "demo.h"
#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	set<string> final_stations;
	set<string> states_needed;
	map<string, set<string>> stations;

	states_needed.insert("mt");
	states_needed.insert("wa");
	states_needed.insert("or");
	states_needed.insert("id");
	states_needed.insert("nv");
	states_needed.insert("ut");
	states_needed.insert("ca");
	states_needed.insert("az");

	set<string> kone_set, ktwo_set, kthree_set, kfour_set, kfive_set;
	kone_set.insert("id");
	kone_set.insert("nv");
	kone_set.insert("ut");
	ktwo_set.insert("wa");
	ktwo_set.insert("id");
	ktwo_set.insert("mt");
	kthree_set.insert("or");
	kthree_set.insert("nv");
	kthree_set.insert("ca");
	kfour_set.insert("nv");
	kfour_set.insert("ut");
	kfive_set.insert("ca");
	kfive_set.insert("az");

	stations.insert(pair<string, set<string>>("kone", kone_set));
	stations.insert(pair<string, set<string>>("ktwo", ktwo_set));
	stations.insert(pair<string, set<string>>("kthree", kthree_set));
	stations.insert(pair<string, set<string>>("kfour", kfour_set));
	stations.insert(pair<string, set<string>>("kfive", kfive_set));

	RadioDistribute(final_stations, states_needed, stations);

	set<string>::const_iterator final_set_cit;
	for (final_set_cit = final_stations.cbegin(); final_set_cit != final_stations.cend(); final_set_cit++)
	{
		cout << (*final_set_cit) << " ";
	}
	cout << endl;
	getchar();
	return 0;
}

