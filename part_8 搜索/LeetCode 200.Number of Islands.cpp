/*
 * @Author: xuhuanhuan 
 * @Date: 2020-03-10 09:38:17 
 * @Last Modified by:   xuhuanhuan 
 * @Last Modified time: 2020-03-10 09:38:17 
 */
#include <vector>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        int island_num = 0;
        vector<vector<int>> mark(grid.size(), vector<int>(grid[0].size(),0));
        for(int x = 0; x < grid.size(); ++x){
            for(int y = 0; y < grid[x].size(); ++y){
                if(grid[x][y] == '1' && mark[x][y] == 0){
                    //BFS(grid, mark, x, y);
                    DFS(grid, mark, x, y);
                    ++island_num;
                }
            }
        }
        return island_num;
    }
    
private:
//* 深度优先遍历
    void DFS(vector<vector<char>> &grid, vector<vector<int>> &mark, int x, int y){
        const int dx[] = {-1, 0, 1, 0};
        const int dy[] = {0, -1, 0, 1};
        mark[x][y] = 1;
        for(int i = 0; i < 4; ++i){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[new_x].size())
                continue;
            if(grid[new_x][new_y] == '1' && mark[new_x][new_y] == 0)
                DFS(grid, mark, new_x, new_y);
        }
    }
    
    //* 宽度优先遍历
    void BFS(vector<vector<char>> &grid, vector<vector<int>> &mark, int x, int y){
        queue<pair<int, int> > Q;
        Q.push(make_pair(x, y));
        mark[x][y] = 1;
        const int dx[] = {-1, 0, 1, 0};
        const int dy[] = {0, -1, 0, 1};
        while(!Q.empty()){
            int x_q = Q.front().first;
            int y_q = Q.front().second;
            Q.pop();
            for(int i = 0; i < 4; ++i){
                int new_x = x_q + dx[i];
                int new_y = y_q + dy[i];
                if(new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[x].size())
                    continue;
                if(grid[new_x][new_y] == '1' && mark[new_x][new_y] == 0){
                    Q.push(make_pair(new_x, new_y));
                    mark[new_x][new_y] = 1;
                }
            }
        }
    }
};

int main()
{
    vector<vector<char> > grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    Solution sol;
    cout << "number of islands : " << sol.numIslands(grid) << endl;
    return 0;
}