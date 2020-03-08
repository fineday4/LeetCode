#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(const std::pair<int, int> &a, const std::pair<int ,int> &b) {
    return a.first > b.first;
}

int get_minimum_stop(int L, int P, std::vector<std::pair<int, int> > &stop){
	if(stop.size() == 0)
		return 0;
	int fuel_path = stop[0].second;
	int max_fuel = fuel_path;
	int max_idx = 0;
	int stop_time = 1;
	for(int idx = 1; idx < stop.size(); ++idx){
		if(fuel_path >= (stop[0].first - stop[idx].first)){
			if(max_fuel < fuel_path + stop[idx].second){
				max_fuel = fuel_path + stop[idx].second;
				max_idx = idx;
			}
		}else{
			if(fuel_path < max_fuel){
				++stop_time;
				fuel_path = max_fuel;
				idx = max_idx;
			}
		}
	}
	return stop_time;
}

int main(){
	std::vector<std::pair<int, int> > stop;
	int N;
	int L;
	int P;
	int distance;
	int fuel;
	stop.push_back(std::make_pair(25, 16));
	stop.push_back(std::make_pair(15, 2));
	stop.push_back(std::make_pair(11, 5));
	stop.push_back(std::make_pair(10, 3));
	stop.push_back(std::make_pair(4, 4));
	stop.push_back(std::make_pair(0, 0));
	// scanf("%d", &N);
	// for (int i = 0; i < N; i++){
	// 	scanf("%d %d", &distance, &fuel);
	// 	stop.push_back(std::make_pair(distance, fuel));
	// }
	// scanf("%d %d", &L, &P);
	printf("(should be 3 )%d\n", get_minimum_stop(L, P, stop));
	return 0;
}
