#include <stdio.h>

#include <vector>
class Solution {
public:
    int jump(std::vector<int>& nums) {
		if(nums.size() < 2){
			return nums.size();
		}
		int min_jump = 1;
		int l_max_len = nums[0];
		int r_max_len = l_max_len;
		for(int idx = 1; idx < nums.size(); ++idx){
			if(idx > l_max_len){
				l_max_len = r_max_len;
				++min_jump;
				--idx;
			}else{
				if(r_max_len < nums[idx] + idx){
					r_max_len = nums[idx] + idx;
				}
			}

		}
		if(l_max_len < nums.size()-1){
			min_jump = -1;
		}
		return min_jump;
    }
};

int main(){
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	Solution solve;
	printf("%d\n", solve.jump(nums));
	return 0;
}
