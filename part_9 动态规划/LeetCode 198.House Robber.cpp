#include <stdio.h>
#include<algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(std::vector<int>& nums) {
		if(nums.size() == 0)
			return 0;
		if(nums.size() == 1)
			return nums[0];
		vector<int> worthy(nums.size(), 0);
		worthy[0] = nums[0];
		worthy[1] = nums[1];
		for(int j = 2; j < nums.size(); ++j)
			worthy[j] = max(worthy[j-1], worthy[j-2] + nums[j]);
		return worthy[nums.size()-1];
    }
};

int main(){
	Solution solve;
	std::vector<int> nums;
	nums.push_back(5);
	nums.push_back(2);
	nums.push_back(6);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(7);	
	printf("%d\n", solve.rob(nums));
	return 0;
}
