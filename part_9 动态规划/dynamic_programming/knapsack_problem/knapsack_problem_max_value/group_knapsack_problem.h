/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-21 15:29:31 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-21 22:02:07
 */

 #include "../knapsack_problem.h"

namespace dynamic_programming{
    void knapsack_Problem::group_knapsack_problem(size_t IN_v1, std::vector<std::vector<size_t> > IN_weights_2D, std::vector<std::vector<size_t> > IN_values_2D, size_t &OUT_max)
    {
        size_t len = IN_weights_2D.size();
        std::vector<size_t> max_values(IN_v1+1, 0);
        for(size_t i = 0; i < len; ++i){
            size_t ilen = IN_weights_2D[i].size();
            std::vector<size_t> max_value(IN_v1 + 1, 0);
            for(size_t idx = 0; idx < ilen; ++idx){
                size_t weight = IN_weights_2D[i][idx];
                size_t value = IN_values_2D[i][idx];
                for(size_t iidx = IN_v1; iidx >= weight; --iidx){
                    if(max_value[iidx] < value)
                        max_value[iidx] = value;
                }
            }
            for(size_t idx = IN_v1; idx > 0; --idx){
                for(size_t iidx = idx; iidx >= 0; --iidx){
                    if(max_values[idx] < max_values[idx - iidx] + max_value[iidx])
                        max_values[idx] = max_values[idx - iidx] + max_value[iidx];
                }
            }
        }
        OUT_max = max_values[IN_v1];
    }
 }