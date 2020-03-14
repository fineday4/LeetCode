/*
 * @Author: xuhuanhuan 
 * @Date: 2020-03-10 18:48:07 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-03-10 19:15:34
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4)
            return false;
        int sum = 0;
        for(auto i : nums){
            sum += i;
        }
        if(sum%4 != 0){
            return false;
        }
        int buckets[4] = {0};
        sort(nums.rbegin(), nums.rend());  //! 递减排序的方法，使用逆迭代器。
        return generate(0, sum/4, nums, buckets);
    }

private:
    bool generate(int idx, int target, vector<int> &nums, int buckets[4]){
        if(idx >= nums.size())
            return buckets[0] == buckets[1] && buckets[1] == buckets[2] && buckets[2] == buckets[3];

        for(int j = 0; j < 4; ++j){
            if(buckets[j]+nums[idx] > target)
                continue;
            buckets[j] += nums[idx];
            if(generate(idx+1, target, nums, buckets)){
                return true;
            }
            buckets[j] -= nums[idx];
        }
        return false;
    }
};

int main()
{
    vector<int> test1 = {1,1,2,2,2};
    Solution sol;
    cout << "result: " << sol.makesquare(test1) << endl;

    return 0;
}