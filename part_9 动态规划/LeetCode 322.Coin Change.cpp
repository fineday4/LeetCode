#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
//*动态规划
#if 0
    int coinChange(std::vector<int>& coins, int amount) {
		vector<int> dp(amount+1, -1);
		dp[0] = 0;
		sort(coins.begin(), coins.end());

		for(int i = coins[0]; i <= amount; ++i){
			for(int j = 0; j < coins.size(); ++j){
				if(i < coins[j])
					continue;
				if(dp[i-coins[j]] != -1){
					if(dp[i] == -1 || dp[i] > dp[i-coins[j]]+1)
						dp[i] = dp[i-coins[j]] + 1;
				}
			}
		}
		return dp[amount];		
    }
#endif
	//*回溯法,没经过验证

	int coinChange(vector<int> &coins, int amount){
		int num = 0;
		bool flag = false;
		if(amount == 0)
			return 0;
		for(auto j : coins){
			if(j == amount){
				flag = true;
				return 1;
			}
			if(amount > j){
				flag = true;
				int tmp = coinChange(coins, amount-j);
				if(tmp > 0 && (num == 0 || num > tmp + 1))
					num = tmp + 1;
			}else{
				if(!flag)
					return -1;
			}
		}
		return num;
	}
};

int main(){	
	Solution solve;
	std::vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	coins.push_back(7);
	coins.push_back(10);	
	for (int i = 1; i<= 14; i++){
		printf("dp[%d] = %d\n", i, solve.coinChange(coins, i));
	}
	return 0;
}
