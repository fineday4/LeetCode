#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
		vector<int> steps(n+1, 0);
		steps[0] = 0;
		steps[1] = 1;
		steps[2] = 2;
		for(int j = 3; j <= n; ++j)
			steps[j] = steps[j-1] + steps[j-2]; //*状态方程为：f(k) = f(k-1) + f(k-2).即，第k阶的走法可以是f(k-1)的走法上再走一阶与f(k-2)的走法上再走两阶的和	
		return steps[n];
    }
	
};

int main(){
	Solution solve;
	printf("%d\n", solve.climbStairs(3));	
	return 0;
}
