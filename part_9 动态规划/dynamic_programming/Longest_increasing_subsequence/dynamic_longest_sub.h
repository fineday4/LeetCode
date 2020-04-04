/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-26 21:28:59 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-26 21:43:04
 */
#include "longest_in_sub.h"

namespace dynamic_programming{
    void longest_in_sub::dynamic_longest_sub(const std::vector<int> &IN_vec, int &OUT_max)
    {
        size_t len = IN_vec.size();
        std::vector<int> record_max(len, 1);
        for(int i = 1; i < len; ++i){
            for(int j = i-1; j >= 0; --j){
                if(IN_vec[i] > IN_vec[j]){
                    if(record_max[i] < record_max[j] + 1)
                        record_max[i] = record_max[j] + 1;
                }
            }
        }
        auto maxposition = std::max_element(record_max.begin(), record_max.end());
        OUT_max = *maxposition;
    }
}