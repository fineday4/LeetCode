/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-25 18:19:31 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-25 18:19:57
 *
 *华为机试在线训练--购物单
 */

 #include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::tuple;

int main()
{
    size_t N, m;
    cin >> N >> m;
    size_t v = 0, p = 0, q = 0;
    vector<vector<tuple<size_t, size_t, size_t> > > group_data;
    vector<tuple<size_t, size_t, size_t> > lot_data;
    for(size_t i = 0; i < m; ++i){
        cin >> v >> p >> q;
        if(q == 0){
            vector<tuple<size_t, size_t, size_t> > tmp;
            tmp.push_back(std::make_tuple(v,v*p,i+1));
            group_data.push_back(tmp);
        }else{
            lot_data.push_back(std::make_tuple(v,v*p,q));
        }
    }
    for(auto &i : lot_data){
        for(auto &j : group_data){
            if(std::get<2>(j[0]) == std::get<2>(i)){
                j.push_back(i);
                break;
            }
        }
    }
    //*动态规划
    vector<size_t> max_value(N+1,0);
    vector<size_t> tmp_max_value(N+1, 0);
    for(size_t i = 0; i != group_data.size(); ++i){
        size_t main_weight = std::get<0>(group_data[i][0]);
        size_t main_value = std::get<1>(group_data[i][0]);
        tmp_max_value = max_value;
        for(size_t j = 1; j < group_data[i].size(); ++j){
            size_t weight = std::get<0>(group_data[i][j]);
            size_t value = std::get<1>(group_data[i][j]);
            for(size_t k = N; k >= weight; --k){
                tmp_max_value[k] = (tmp_max_value[k] > tmp_max_value[k - weight] + value? tmp_max_value[k] : tmp_max_value[k - weight] + value);
            }
        }
        for(size_t k = N; k >= main_weight; --k){
            if(tmp_max_value[k-main_weight] + main_value > max_value[k]){
                max_value[k] = tmp_max_value[k-main_weight] + main_value;
            };
        }
        tmp_max_value.clear();
    }

    cout << max_value[N] << endl;
    return 0;
}
