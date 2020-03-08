/*
 * @Author: xuhuanhuan 
 * @Date: 2020-03-08 20:51:14 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-03-08 21:04:24
 */

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

void gerneta_sub(vector<int> &IN_nums, vector<vector<int> > &OUT_res, vector<int> &sub, int idx){
    if(idx > IN_nums.size() - 1)
        return;
    sub.push_back(IN_nums[idx]);
    if(find(OUT_res.begin(), OUT_res.end(), sub) == OUT_res.end()){
        OUT_res.push_back(sub);
    }
    gerneta_sub(IN_nums, OUT_res, sub, idx+1);
    sub.pop_back();
    gerneta_sub(IN_nums, OUT_res, sub, idx+1);
}

void subsetsWithDup(vector<int> &IN_nums, vector<vector<int> > &OUT_res)
{
    if(IN_nums.size() == 0)
        return ;
    sort(IN_nums.begin(), IN_nums.end());
    vector<int> sub;
    gerneta_sub(IN_nums, OUT_res, sub, 0);
}

int main()
{
    vector<int> IN_set{2,1,2,2};
    vector<vector<int> > OUT_all_sub;
    vector<int> sub;
    OUT_all_sub.push_back(sub);
    subsetsWithDup(IN_set, OUT_all_sub);
    for(auto i : OUT_all_sub){
        cout << "items: ";
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}