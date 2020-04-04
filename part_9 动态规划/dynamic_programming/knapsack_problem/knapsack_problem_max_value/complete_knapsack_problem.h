/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-20 15:09:37 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-21 21:20:53
 */

#include "../knapsack_problem.h"
namespace dynamic_programming{
    void knapsack_Problem::complete_knapsack_problem(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values, size_t &OUT_max)
    {
         std::vector<size_t> max_values(IN_v + 1, 0);
         size_t len = IN_weights.size();
         for(size_t i = 0; i < len; ++i){
             size_t weight = IN_weights[i];
             size_t value = IN_values[i];
             for(size_t j = weight; j <= IN_v; ++j){
                 if(max_values[j] < max_values[j - weight] + value)
                     max_values[j] = max_values[j - weight] + value;   
             }
         } 
         OUT_max = max_values[IN_v]; 
    }
}