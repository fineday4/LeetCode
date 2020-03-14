#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		int max_num = dp[0];
		for(int i = 1; i < nums.size(); ++i){
			dp[i] = max(nums[i], dp[i-1] + nums[i]);
			if(max_num < dp[i])
				max_num = dp[i];
		}		
		return max_num;
    }
};

int main(){
	Solution solve;
	std::vector<int> nums;
	nums.push_back(-2);
	nums.push_back(1);
	nums.push_back(-3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(4);
	printf("%d\n", solve.maxSubArray(nums));
	return 0;
}
