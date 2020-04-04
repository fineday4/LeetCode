/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-26 12:50:38 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-26 18:14:43
 *
 *华为机试在线训练--合唱团
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    int tmp;
    vector<int> vec_num;
    while(cin >> num){
        vec_num.clear();
        for(int idx = 0; idx < num; ++idx){
            cin >> tmp;
            vec_num.push_back(tmp);
        }
        vector<int> forward_list(num, 1);
        for(int i = 1; i < num; ++i){
            int max = 1;
            for(int j = i-1; j >= 0; --j){
                if(vec_num[i] > vec_num[j]){
                    if(max < forward_list[j] + 1)
                        max = forward_list[j] +1;
                }
            }
            forward_list[i] = max;
        }
        vector<int> reverse_list(num, 1);
        reverse(vec_num.begin(),vec_num.end());
            for(int i = 1; i < num; ++i){
            int max = 1;
            for(int j = i-1; j >= 0; --j){
                if(vec_num[i] > vec_num[j]){
                    if(max < reverse_list[j] + 1)
                        max = reverse_list[j] +1;
                }
            }
            reverse_list[i] = max;
        }
        int max = 0;
        for(int idx = 0; idx < num; ++idx){
            for(int iidx = num-idx-1; iidx >= 0; --iidx){
                if(max < forward_list[idx] + reverse_list[iidx])
                    max = forward_list[idx] + reverse_list[iidx];
            }
        }
        cout << num - max + 1 << endl;
    }
    return 0;
}