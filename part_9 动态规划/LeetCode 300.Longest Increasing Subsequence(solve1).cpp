#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
		if(nums.size() == 0)
			return 0;
		int lis = 1;
		vector<int> dp(nums.size(), 1);
		for(int i = 1; i < nums.size(); ++i){
			for(int j = 0; j < i; ++j){
				if(nums[j] < nums[i] && dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			}
			if(lis < dp[i]){
				lis = dp[i];
			}
		}
		return lis;
    }
};

int main(){
	int test[] = {10, 9, 2, 5, 3, 7, 101, 18};
	std::vector<int> nums;
	for (int i = 0; i < 8; i++){
		nums.push_back(test[i]);
	}
	Solution solve;
	printf("%d\n", solve.lengthOfLIS(nums));
	return 0;
}
