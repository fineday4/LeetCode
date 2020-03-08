/*
 * @Author: xuhuanhuan 
 * @Date: 2020-03-08 21:24:12 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-03-08 21:53:12
 */
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

void generator(vector<int> &IN_nums, set<vector<int> > &OUT_res, vector<int> &IN_sub, int idx, int target){
    if(idx > IN_nums.size() - 1)
        return;
    IN_sub.push_back(IN_nums[idx]);
    int sum = accumulate(IN_sub.begin(), IN_sub.end(), 0);
    if(sum == target){
        for(auto i : IN_sub){
            cout << " i: " << i;
        }
        cout << endl;
        if(find(OUT_res.begin(), OUT_res.end(), IN_sub) == OUT_res.end())
            OUT_res.insert(IN_sub);
        generator(IN_nums, OUT_res, IN_sub, idx+1, target);
        IN_sub.pop_back();
        generator(IN_nums, OUT_res, IN_sub, idx+1, target);        
    }else if(sum > target){
        IN_sub.pop_back();
        generator(IN_nums, OUT_res, IN_sub, idx+1, target);
    }else{
        generator(IN_nums, OUT_res, IN_sub, idx+1, target);
        IN_sub.pop_back();
        generator(IN_nums, OUT_res, IN_sub, idx+1, target);
    }
}

int main()
{
    vector<int> nums{10, 1, 2, 7, 6, 1, 5};
    set<vector<int> > res;
    vector<int> sub;
    sort(nums.begin(), nums.end());
    generator(nums, res, sub, 0, 8);
    for(auto i : res){
        cout << "items: ";
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}