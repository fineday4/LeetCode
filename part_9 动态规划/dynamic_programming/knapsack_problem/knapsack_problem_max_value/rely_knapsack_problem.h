/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-22 19:42:47 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-22 20:04:56
 */

 #include "../knapsack_problem.h"

namespace dynamic_programming{
    void knapsack_Problem::rely_knapsack_problem(size_t IN_v1, std::vector<std::vector<size_t> > IN_weights_2D, std::vector<std::vector<size_t> > IN_values_2D, size_t &OUT_max)
    {
        size_t group_len = IN_weights_2D.size();
        std::vector<size_t> max_values(IN_v1 + 1, 0);
        for(size_t group_idx = 0; group_idx < group_len; ++group_idx){
            
            size_t items_len = IN_weights_2D[group_idx].size();
            size_t main_weight = IN_weights_2D[group_idx][0];
            size_t main_value = IN_values_2D[group_idx][0];
            std::vector<size_t> tmp_max_values(max_values);
            for(size_t items_idx = 1; items_idx < items_len; ++items_idx){
                size_t weight = IN_weights_2D[group_idx][items_idx];
                size_t value = IN_values_2D[group_idx][items_idx];
                for(size_t weight_cursor = IN_v1; weight_cursor >= weight; --weight_cursor){
                    if(tmp_max_values[weight_cursor] < tmp_max_values[weight_cursor - weight] + value)
                        tmp_max_values[weight_cursor] = tmp_max_values[weight_cursor - weight] + value;
                }
            }
            for(size_t weight_cursor = IN_v1; weight_cursor >= main_weight; --weight_cursor){
                if(max_values[weight_cursor] < tmp_max_values[weight_cursor - main_weight] + main_value)
                    max_values[weight_cursor] = tmp_max_values[weight_cursor - main_weight] + main_value;
            }
        }
        OUT_max = max_values[IN_v1];
    }
 }