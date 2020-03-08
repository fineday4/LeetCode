#include <stdio.h>

#include <vector>
class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
		else if(nums.size() < 2)
			return nums.size();
		int max_len = 1;
		enum STATE{BEG, UP, DOWN};
		STATE state = BEG;
		for(int idx = 0; idx < nums.size()-1; ++idx){
			switch(state){
				case BEG:{
					if(nums[idx] < nums[idx+1]){
						state = UP;
						++max_len;
					}else if(nums[idx] > nums[idx+1]){
						state = DOWN;
						++max_len;
					}
				}break;
				case UP:{
					if(nums[idx] > nums[idx+1]){
						state = DOWN;
						++max_len;
					}
				}break;
				case DOWN:{
					if(nums[idx] < nums[idx+1]){
						state = UP;
						++max_len;
					}
				}break;
			}
		}
		return max_len;
    }
};

int main(){
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(17);
	nums.push_back(5);
	nums.push_back(10);
	nums.push_back(13);
	nums.push_back(15);
	nums.push_back(10);
	nums.push_back(5);
	nums.push_back(16);
	nums.push_back(8);
	Solution solve;
	printf("%d\n", solve.wiggleMaxLength(nums));
	return 0;
}
