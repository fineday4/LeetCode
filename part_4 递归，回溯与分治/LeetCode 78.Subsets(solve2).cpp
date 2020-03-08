/*
 * @Author: xuhuanhuan 
 * @Date: 2020-03-08 20:25:55 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-03-08 20:32:51
 */
#include <iostream>
#include <vector>

using namespace std;

void getSubset(vector<int> &IN_set, vector<vector<int> > &OUT_all_sub){
    int max_set = 1 << IN_set.size();
    for(int i = 0; i < max_set; ++i){
        vector<int> sub;
        for(int idx = 0; idx < IN_set.size(); ++idx){
            if(i & (1 << idx)){
                sub.push_back(IN_set[idx]);
            }
        }
        OUT_all_sub.push_back(sub);
    }
}

int main()
{
    vector<int> IN_set{1,2,3};
    vector<vector<int> > OUT_all_sub;
    vector<int> sub;
    getSubset(IN_set, OUT_all_sub);
    for(auto i : OUT_all_sub){
        cout << "items: ";
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}