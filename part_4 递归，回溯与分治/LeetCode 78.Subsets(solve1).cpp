/*
 * @Author: xuhuanhuan 
 * @Date: 2020-03-08 20:07:08 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-03-08 20:24:01
 */
#include <iostream>
#include <vector>

using namespace std;

void getSubset(vector<int> &IN_set, vector<vector<int> > &OUT_all_sub, vector<int> &sub, int idx){
    if(idx > IN_set.size()-1)
        return;
    sub.push_back(IN_set[idx]);
    OUT_all_sub.push_back(sub);
    getSubset(IN_set, OUT_all_sub, sub, idx + 1);
    sub.pop_back();
    getSubset(IN_set, OUT_all_sub, sub, idx+1);
}

int main()
{
    vector<int> IN_set{1,2,3};
    vector<vector<int> > OUT_all_sub;
    vector<int> sub;
    OUT_all_sub.push_back(sub);
    getSubset(IN_set, OUT_all_sub, sub, 0);
    for(auto i : OUT_all_sub){
        cout << "items: ";
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}