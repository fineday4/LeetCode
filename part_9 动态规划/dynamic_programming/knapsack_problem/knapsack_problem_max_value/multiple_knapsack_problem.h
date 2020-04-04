/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-21 20:37:15 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-21 22:01:20
 */
 #include "../knapsack_problem.h"
 namespace dynamic_programming{
    void knapsack_Problem::multiple_knapsack_problem(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values,std::vector<size_t> IN_nums, size_t &OUT_max)
    {
        size_t len = IN_weights.size();
        std::vector<size_t> max_values(IN_v+1, 0);
        for(size_t item_idx = 0; item_idx < len; ++item_idx){
            size_t num_max_idx = IN_nums[item_idx];
            size_t weight = IN_weights[item_idx];
            size_t value = IN_values[item_idx];
            for(size_t num_idx = 0; num_idx < num_max_idx; ++num_idx){
                for(size_t weight_cursor = IN_v; weight_cursor >= weight; --weight_cursor){
                    if(max_values[weight_cursor] < max_values[weight_cursor - weight] + value)
                        max_values[weight_cursor] = max_values[weight_cursor - weight] + value;
                }
            }
        }
        OUT_max = max_values[IN_v];
    }
 }