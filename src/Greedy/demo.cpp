#include "demo.h"

void RadioDistribute(set<string>& final_stations, const set<string>& states_needed, const map<string, set<string>>& stations)
{
	string candidate_station;
	set<string> cur_states_needed = states_needed;
	set<string> last_states_needed = cur_states_needed;
	set<string>::iterator needed_it;
	map<string, set<string>>::const_iterator station_cit;
	int cur_candidate_num = 0, last_candidate_num = 0;
	string cur_key;
	set<string> cur_value_set;
	set<string>::const_iterator cur_value_set_cit;
	bool isFind, isExist;
	while (cur_states_needed.size() != 0)
	{
		last_candidate_num = 0;
		isFind = false;
		for (station_cit = stations.cbegin(); station_cit != stations.cend(); station_cit++)
		{
			cur_key = (*station_cit).first;
			cur_value_set = (*station_cit).second;
			cur_candidate_num = 0;
			for (cur_value_set_cit = cur_value_set.cbegin(); cur_value_set_cit != cur_value_set.cend(); cur_value_set_cit++)
			{
				for (needed_it = cur_states_needed.begin(); needed_it != cur_states_needed.end(); needed_it++)
				{
					if ((*cur_value_set_cit) == (*needed_it))
					{
						cur_candidate_num++;
					}
				}
			}
			if (cur_candidate_num > last_candidate_num)	// 候选
			{
				candidate_station = cur_key;
				isFind = true;	// 找到候选解
			}
		}
		// 找出候选后，得到还未命中的记录
		last_states_needed = cur_states_needed;
		cur_value_set = stations.at(candidate_station);
		cur_states_needed.clear();
		for (needed_it = last_states_needed.begin(); needed_it != last_states_needed.end(); needed_it++)
		{
			isExist = false;
			for (cur_value_set_cit = cur_value_set.cbegin(); cur_value_set_cit != cur_value_set.cend(); cur_value_set_cit++)
			{
				if ((*needed_it) == (*cur_value_set_cit))	// 表示这个记录已经命中
				{
					isExist = true;
					break;
				}
			}
			if (!isExist)
			{
				cur_states_needed.insert((*needed_it));
			}
		}
		if (isFind) final_stations.insert(candidate_station);	// 保存最优候选
	}
}