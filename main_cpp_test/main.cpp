
#include <iostream>

#include <stdio.h>

#include <iostream>
#include <fstream>

#include <string>
#include <sstream>
#include <vector>
#include <stdint.h>  // uint64_t
#include <assert.h>

#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <algorithm>    // std::sort
#include <utility>

#include <stack>
#include <memory.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <thread>
#include <mutex>



using namespace std; 

template<typename T> string tools_to_string(const T &t)
{
	ostringstream ss;
	ss << t;
	return ss.str();
}


void exec_e(float &e)
{
	//cout << e << " ";
	e *= 10.0f;
	e += 0.1f;
}


void exec_multi_threads_on_data(vector<float>& arr_src, const int& N, const int& td_num, void (*cb)(float &e))
{

#define FLAG_USE_MULTIPLE_THREAD_ 1 

#define FLAG_USE_SINGLE_THREAD_ (!FLAG_USE_MULTIPLE_THREAD_) 


	//typedef  pair<int, std::thread> i_td;
	//int td_num_real = td_num - 1; 
	int mod_num = ceil (N * 1.0f / td_num );
	vector< pair<int, std::thread> > arr_pair_i_td{};

	arr_pair_i_td.resize(td_num);

	//arr_pair_i_td.resize(N % mod_num == 0 ? N / mod_num : N / mod_num + 1);

	int cnt = 0;
	int cnt_arr = 0;

	cnt = 0;
	int flag_break_at_pad = 0;
	int cnt_threads = 0; 
	for(int i=0;i<td_num;i++)
	{
		auto id_td = i; 
		int start ; 
		int end; 
		if(i*mod_num + mod_num <= N)
		{
			end = i * mod_num + mod_num; 
		}
		else
		{
			int pad_num = N % mod_num; 
			end = i * mod_num + pad_num; 
			flag_break_at_pad = 1; 
		}
		start = i * mod_num; 


		cnt_threads++; 
		auto pair_i_i = make_pair(start, end);
		//auto pair_i_i = make_pair(cnt, cnt + mod_num > N ? N : cnt + mod_num);


		arr_pair_i_td[id_td].first = id_td;
		arr_pair_i_td[id_td].second = thread([&cb](int id_td, vector<float>& arr_src, pair<int, int> pair_i_i) {

#if 1
				float sleep_time_seconds = id_td * 0.02f;
				string cmd_sleep = string("sleep ") + tools_to_string(sleep_time_seconds) + "";
				system(cmd_sleep.c_str());
				//cout << cmd_sleep << endl; 
#endif 
				cout << "- id_td: " << id_td << endl;

				for (auto i = pair_i_i.first; i < pair_i_i.second; i++)
				{
				//cout << arr_src[i] << " ";
				cb(arr_src[i]);
				}
				cout << endl << "--------------------" << endl;

				},
				id_td, std::ref(arr_src), pair_i_i
				);





#if FLAG_USE_SINGLE_THREAD_
		cout << "- FLAG_USE_SINGLE_THREAD_ " << endl; 
		arr_pair_i_td[id_td].second.join();
#endif 

		if (flag_break_at_pad) break; 
	}

	cout << "- cnt_threads : " << cnt_threads << endl; 

#if FLAG_USE_MULTIPLE_THREAD_  
	for (auto& e_pair : arr_pair_i_td)
	{
		e_pair.second.join();
	}

#endif


	arr_pair_i_td.clear();





}


//main_
int main() {

#if 1 
	const int N = (const int)(1e4 + 0);
	const int td_num = 4; 


	vector<float> arr_src{};
	arr_src.resize(N);
	int  cnt = 0;
	for (auto &e : arr_src)
	{
		e = (cnt++) * 1.0f;
	}

	exec_multi_threads_on_data(arr_src, N, td_num, exec_e);

	cout << arr_src[1] << endl; 
	cout << arr_src[N - 1] << endl; 

	arr_src.clear(); 
#endif 

}


