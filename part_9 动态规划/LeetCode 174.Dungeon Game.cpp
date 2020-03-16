#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int> >& dungeon) {
		if(dungeon.size() == 0)
			return 0;
		
		int raw = dungeon.size();
		int column = dungeon[0].size();
		vector<vector<int> > res(raw, vector<int>(column, 0));
		res[raw-1][column-1] = max(1, 1-dungeon[raw-1][column-1]);
		for(int i = raw-2; i >= 0; --i){
			res[i][column-1] = max(1, res[i+1][column-1]-dungeon[i][column-1]);
		}

		for(int j = column-2; j >= 0; --j){
			res[raw-1][j] = max(1, res[raw-1][j]-dungeon[raw-1][j]);
		} 

		for(int i = raw-2; i >= 0; --i){
			for(int j = column-2; j >= 0; --j){
				int min_elem = min(res[i][j+1], res[i+1][j]);
				res[i][j] = max(1, min_elem - dungeon[i][j]);
			}
		}

		return res[0][0];
    }
};

int main(){
	int test[][3] = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
	std::vector<std::vector<int> > dungeon;
	for (int i = 0; i < 3; i++){
		dungeon.push_back(std::vector<int>());
		for (int j = 0; j < 3; j++){
			dungeon[i].push_back(test[i][j]);
		}
	}
	Solution solve;
	printf("%d\n", solve.calculateMinimumHP(dungeon));
	return 0;
}
