/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-26 21:44:22 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-26 22:19:09
 *
 * 这个实现不好~~~~
 */

#include "longest_in_sub.h"

namespace dynamic_programming{
    void longest_in_sub::dynamic_longest_sub_scheme(const std::vector<int> &IN_vec, std::vector<int> &OUT_max_scheme)
    {
        size_t len = IN_vec.size();
        std::vector<int> record_max(len, 1);
        std::vector<std::vector<int> > max_scheme(len);
        for(int i = 1; i < len; ++i){
            int idx = 0;
            bool is_set = false;
            for(int j = i-1; j >= 0; --j){
                if(IN_vec[i] > IN_vec[j]){
                    if(record_max[i] < record_max[j] + 1){
                        record_max[i] = record_max[j] + 1;
                        idx = j;
                        is_set = true;
                    }
                }
            }
            max_scheme[i].push_back(i);
            if(is_set)
                max_scheme[i].push_back(idx);
        }
        auto maxposition = std::max_element(record_max.begin(), record_max.end());
        int max_idx = maxposition - record_max.begin();
        while(max_idx >= 0){
            OUT_max_scheme.push_back(IN_vec[max_idx]);
            if(max_scheme[max_idx].size() == 2){
                max_idx = max_scheme[max_idx][1];
            }else{
                max_idx = -1;
            }
        }
        std::reverse(OUT_max_scheme.begin(), OUT_max_scheme.end());
    }
}