
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int> >& triangle){
		//* 优化了数据结构，将存储结果的二维数据改为一维数组
		vector<int> dp(triangle.size(), 0);
		dp[0] = triangle[0][0];;
		for(int i = 1; i < triangle.size(); ++i){
			for(int j = triangle[i].size()-1; j >= 0; --j){
				if(j > 0 && j < triangle[i].size()-1)
					dp[j] = min(dp[j] + triangle[i][j], dp[j-1] + triangle[i][j]);
				else if(j == 0)
					dp[j] = dp[j] + triangle[i][j];
				else
					dp[j] = dp[j-1] + triangle[i][j];
			}
		}
		return *min_element(dp.begin(), dp.end());		
    }
};

int main(){
	std::vector<std::vector<int> > triangle;
	int test[][10] = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	for (int i = 0; i < 4; i++){
		triangle.push_back(std::vector<int>());
		for (int j = 0; j < i + 1; j++){
			triangle[i].push_back(test[i][j]);
		}
	}
	Solution solve;
	printf("%d\n", solve.minimumTotal(triangle));
	return 0;
}
