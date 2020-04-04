/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-27 14:39:41 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-27 23:07:55
 *
 *华为机试在线训练--数据分类处理
 */




#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    long i, r;
    while(cin >> i){
        vector<string> i_vec;
        vector<string> r_vec;
        for(size_t idx = 0; idx < i; ++idx){
            string num;
            cin >> num;
            i_vec.push_back(num);
        }
        cin >> r;
        for(size_t idx = 0; idx < r; ++idx){
            string num;
            cin >> num;
            r_vec.push_back(num);
        }
        sort(r_vec.begin(), r_vec.end(),[](const string &a, const string &b){
            if(stoi(a) < stoi(b))
                return true;
            return false;
        });
        int len = r_vec.size();
        for(int rdx = 0;rdx < len-1; ++rdx){
            for(int rrdx = rdx + 1; rrdx < len; ++rrdx){
                if(r_vec[rdx] == r_vec[rrdx]){
                    r_vec.erase(r_vec.begin() + rrdx);
                    --rrdx;
                    --len;
                }
            }
        }
        map<string, vector<int> > res;
        int print_num=0;
        for(auto &r : r_vec){
            for(int idx = 0; idx < i_vec.size(); ++idx){
                //! 寻找子串的方法
                if(i_vec[idx].find(r) != string::npos){
                    ++print_num;
                    res[r].push_back(idx);
                }
            }
        }
        print_num += print_num;
        print_num += 2*res.size();
        cout << print_num;
        for(auto &i : r_vec){
            if(res[i].size()){
                cout << " " << i << " " << res[i].size();
                for(auto idx : res[i]){
                    cout << " " << idx << " " << i_vec[idx];
                }
            }
        }
        cout << endl;
    }
    return 0;
}

#endif