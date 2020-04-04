/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-21 21:02:37 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-21 21:49:32
 */

#include "../knapsack_problem.h"

namespace dynamic_programming{
    void knapsack_Problem::multiple_knapsack_problem_scheme(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values,std::vector<size_t> IN_nums, std::vector<size_t> &OUT_scheme, size_t &OUT_max)
    {
        size_t len = IN_weights.size();
        std::vector<std::vector<size_t> > scheme_matrix(len, std::vector<size_t>(IN_v+1, 0));
        for(size_t item_idx = 0; item_idx < len; ++item_idx){
            size_t num_max_idx = IN_nums[item_idx];
            size_t weight = IN_weights[item_idx];
            size_t value = IN_values[item_idx];
            for(size_t num_idx = 0; num_idx < num_max_idx; ++num_idx){
                for(size_t weight_cursor = IN_v; weight_cursor >= weight; --weight_cursor){
                    if(item_idx){
                        if(scheme_matrix[item_idx-1][weight_cursor] < scheme_matrix[item_idx-1][weight_cursor - weight] + value)
                            scheme_matrix[item_idx][weight_cursor] = scheme_matrix[item_idx-1][weight_cursor - weight] + value;
                        else
                            scheme_matrix[item_idx][weight_cursor] = scheme_matrix[item_idx-1][weight_cursor];
                    }else{
                        if(scheme_matrix[item_idx][weight_cursor] < scheme_matrix[item_idx][weight_cursor - weight] + value)
                            scheme_matrix[item_idx][weight_cursor] = scheme_matrix[item_idx][weight_cursor - weight] + value;
                    }
                }
            }
        }
        int item_idx = len - 1;
        int weight_cursor = IN_v;
        while(item_idx > 0 && weight_cursor > 0){
            size_t weight = IN_weights[item_idx];
            size_t value = IN_values[item_idx];
            if(item_idx){
                if(scheme_matrix[item_idx][weight_cursor] == scheme_matrix[item_idx-1][weight_cursor-weight] + value){
                    OUT_scheme.push_back(item_idx + 1);
                    weight_cursor -= weight;
                }else{
                    --item_idx;
                }
            }else{
                if(scheme_matrix[item_idx][weight_cursor] == scheme_matrix[item_idx][weight_cursor-weight] + value){
                    OUT_scheme.push_back(item_idx + 1);
                    weight_cursor -= weight;
                }else{
                    --item_idx;
                }
            }
        }
        OUT_max = scheme_matrix[len-1][IN_v];
    }
}