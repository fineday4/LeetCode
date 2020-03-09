/*
 * @Author: xuhuanhuan 
 * @Date: 2020-03-09 09:51:56 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-03-09 10:42:50
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void merge_two_vec_sort(vector<pair<int, int> > &sub1_vec, vector<pair<int, int> > &sub2_vec, vector<pair<int, int> > &IN_vec, vector<int> &OUT_count){
    int i = 0, j = 0;
    while(i < sub1_vec.size() && j < sub2_vec.size()){
        if(sub1_vec[i].first <= sub2_vec[j].first){   //! 为什么是 sub1_vec[i].first <= sub2_vec[j].first？因为在满足这个条件之前的所有sub2_vec[j].first都小于sub2[i].first。所以j作为计数器，一直计数到不满足该条件为止。
            IN_vec.push_back(sub1_vec[i]);
            OUT_count[sub1_vec[i].second] += j;
            ++i;
        }else{
            IN_vec.push_back(sub2_vec[j]);
            ++j;
        }
    }
    while(i < sub1_vec.size()){
        IN_vec.push_back(sub1_vec[i]);
        OUT_count[sub1_vec[i].second] += j;
        ++i;
    }
    while(j < sub2_vec.size()){
        IN_vec.push_back(sub2_vec[j]);
        ++j;
    }
}

void merge_sort(vector<pair<int, int> > &IN_vec, vector<int> &OUT_count){
    if(IN_vec.size() < 2){
        return ;
    }
    vector<pair<int, int> > sub1_vec;
    vector<pair<int, int> > sub2_vec;
    int mid = IN_vec.size()/2;
    for(int i = 0; i < mid; ++i){
        sub1_vec.push_back(IN_vec[i]);
    }
    for(int i = mid; i < IN_vec.size(); ++i){
        sub2_vec.push_back(IN_vec[i]);
    }
    merge_sort(sub1_vec, OUT_count);
    merge_sort(sub2_vec, OUT_count);
    IN_vec.clear();
    merge_two_vec_sort(sub1_vec, sub2_vec, IN_vec, OUT_count);
}

int main()
{
    vector<int> nums{5,-7,9,1,3,5,-2,1};
    vector<pair<int, int> > vec;
    for(int i = 0; i < nums.size(); ++i)
        vec.push_back(make_pair(nums[i], i));
    vector<int> count(nums.size(), 0);
    merge_sort(vec, count);

    for(auto i : count)
        cout << " " << i;
    cout << endl;
    return 0;
}