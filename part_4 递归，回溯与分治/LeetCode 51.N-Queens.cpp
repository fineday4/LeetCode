/*
 * @Author: xuhuanhuan 
 * @Date: 2020-03-09 09:07:52 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-03-09 09:48:07
 */

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void down_the_queen(vector<vector<int> > &IN_location, int x_num, int y_num){
    const vector<int> x_pos{-1, -1, -1, 0, 1, 1, 1, 0};
    const vector<int> y_pos{-1, 0, 1, 1, 1, 0, -1, -1};
    for(int i = 0; i < IN_location.size(); ++i){
        for(int j = 0; j < 8; ++j){
            int x_position = x_num + i*x_pos[j];
            int y_position = y_num + i*y_pos[j];
            if(x_position >= 0 && x_position < IN_location.size() && y_position >= 0 && y_position < IN_location.size())
                IN_location[x_position][y_position] = 1;
        }
    }
}

void queens_position(vector<vector<string> > &OUT_n_queens, vector<string> &IN_path, vector<vector<int> > &IN_location, int num, int N){
    if(num == N){
        OUT_n_queens.push_back(IN_path);
        return ;
    }
    vector<vector<int> > tmp_location = IN_location;
    for(int i = 0; i < IN_location[num].size(); ++i){
        if(IN_location[num][i] == 0){
            IN_path[num][i] = 'Q';
            down_the_queen(IN_location, num, i);
            queens_position(OUT_n_queens, IN_path, IN_location, num+1, N);
            IN_location = tmp_location;
            IN_path[num][i] = '.';
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<string> > n_queens;
    vector<string> path(n,string(n,'.'));
    vector<vector<int>> location(n, vector<int>(n, 0));
    queens_position(n_queens, path, location, 0, n);
    for(auto i : n_queens){
        cout << "----------" << endl;
        for(auto j : i){
            cout << j << " " << endl;
        }
        cout << endl;
    }
    return 0;
}