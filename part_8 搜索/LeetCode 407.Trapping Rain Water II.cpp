/*
 * @Author: xuhuanhuan 
 * @Date: 2020-03-10 19:19:20 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-03-10 20:38:21
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Qitem{
    int x;
    int y;
    int h;
    Qitem(int _x, int _y, int _h)
        :x(_x), y(_y), h(_h)
        {}
};

struct cmp{
    bool operator()(const Qitem &a, const Qitem &b){
        return a.h > b.h;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size() < 3 || heightMap[0].size() < 3){
            return 0;
        }
        int raw = heightMap.size();
        int column = heightMap[0].size();
        vector<vector<int>> mark(raw, vector<int>(column, 0));
        priority_queue<Qitem, vector<Qitem>, cmp> Q;
        for(int i = 0; i < heightMap[0].size(); ++i){
            Q.push(Qitem(0, i, heightMap[0][i]));
            Q.push(Qitem(raw-1, i, heightMap[raw-1][i]));
            mark[0][i] = 1;
            mark[raw-1][i] = 1;
        }
        for(int i = 1; i < heightMap.size()-1; ++i){
            Q.push(Qitem(i, 0, heightMap[i][0]));
            Q.push(Qitem(i, column-1,heightMap[i][column-1]));
            mark[i][0] = 1;
            mark[i][column-1] = 1;
        }
        const int dx[4] = {-1, 0, 1, 0};
        const int dy[4] = { 0, 1, 0,-1};
        int result = 0;
        while(!Q.empty()){
            int x = Q.top().x;
            int y = Q.top().y;
            int h = Q.top().h;
            Q.pop();
            for(int j = 0; j < 4; ++j){
                int new_x = x + dx[j];
                int new_y = y + dy[j];
                if(new_x < 0 || new_x >= raw || new_y < 0 || new_y >= column || mark[new_x][new_y]){
                    continue;
                }
                cout << "h: " << h << "  heightMap[new_x][new_y]： " << heightMap[new_x][new_y] << endl;
                if(h > heightMap[new_x][new_y]){
                    result += h - heightMap[new_x][new_y];
                    heightMap[new_x][new_y] = h;
                }
                mark[new_x][new_y] = 1;
                Q.push(Qitem(new_x, new_y, heightMap[new_x][new_y]));
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> heightMap= {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    int res = sol.trapRainWater(heightMap);
    cout << "res: " << res <<endl;
    return 0;
}