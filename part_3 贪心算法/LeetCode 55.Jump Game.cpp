#include <stdio.h>

#include <vector>
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
		int max_len = nums[0] + 0;
		int max_len_idx = 0;
		for(int idx = max_len_idx+1; idx <= max_len && idx < nums.size(); ++idx){
			if(max_len < nums[idx] + idx){
				max_len = nums[idx] + idx;
				max_len_idx = idx;
			}
		}
		if(max_len < nums.size())
			return false;
		return true;
    }
};

int main(){
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(4);
	Solution solve;
	printf("%d\n", solve.canJump(nums));
	return 0;
}
