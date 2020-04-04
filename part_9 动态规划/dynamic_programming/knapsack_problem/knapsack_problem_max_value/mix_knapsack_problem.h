/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-21 22:05:47 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-21 22:18:51
 *
 *混合背包 = 01背包 + 完全背包 + 多重背包
 *
 */

 #include "../knapsack_problem.h"

 namespace dynamic_programming{
     void knapsack_Problem::mix_knapsack_problem(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values,std::vector<size_t> IN_nums, size_t &OUT_max)
     {
         size_t len = IN_weights.size();
         std::vector<size_t> max_values(IN_v+1, 0);
         for(size_t item_idx = 0; item_idx < len; ++item_idx){
             size_t value = IN_values[item_idx];
             size_t weight = IN_weights[item_idx];
             for(auto i : IN_nums){
                 if(i){
                     //01背包( i == 1) & 多重背包(i > 1)
                     for(size_t weight_cursor = IN_v; weight_cursor >= weight; --weight_cursor){
                         if(max_values[weight_cursor] < max_values[weight_cursor-weight] + value)
                             max_values[weight_cursor] = max_values[weight_cursor-weight] + value;
                     }
                 }else{
                     //完全背包(i == 0)
                     for(size_t weight_cursor = weight; weight_cursor <= IN_v; ++weight_cursor){
                         if(max_values[weight_cursor] < max_values[weight_cursor - weight] + value)
                             max_values[weight_cursor] = max_values[weight_cursor - weight] + value;
                     }
                 }
             }
         }
         OUT_max = max_values[IN_v];
     }
 }
