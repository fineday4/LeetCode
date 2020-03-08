#include <stdio.h>

#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const std::pair<int, int> &a, const std::pair<int ,int> &b) {
    return a.first < b.first;
}

class Solution {
public:
    int findMinArrowShots(std::vector<std::pair<int, int> >& points) {
		if(points.size() <= 1){
			return points.size();
		}
		sort(points.begin(), points.end(), cmp);
		int arrow_num = 1;
		int beg = points[0].first;
		int end = points[0].second;
		for(int idx = 1; idx < points.size(); ++idx){
			if(end >= points[idx].first && points[idx].first >= beg){
				if(end > points[idx].second)
					end = points[idx].second;
				beg = points[idx].first;
			}else{
				beg = points[idx].first;
				end = points[idx].second;
				++arrow_num;
			}
		}	
		return arrow_num;	
    }
};

int main(){
	std::vector<std::pair<int, int> > points;
	points.push_back(std::make_pair(10, 16));
	points.push_back(std::make_pair(2, 8));
	points.push_back(std::make_pair(1, 6));
	points.push_back(std::make_pair(7, 12));	
	Solution solve;
	printf("%d\n", solve.findMinArrowShots(points));
	return 0;
}
