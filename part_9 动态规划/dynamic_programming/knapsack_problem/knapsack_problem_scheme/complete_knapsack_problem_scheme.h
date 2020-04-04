/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-21 14:43:23 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-21 21:30:52
 */
 
#include "../knapsack_problem.h"

namespace dynamic_programming{
    void knapsack_Problem::complete_knapsack_problem_scheme(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values, std::vector<size_t> &OUT_scheme, size_t &OUT_max)
    {
        size_t len = IN_weights.size();
        std::vector<std::vector<size_t> > scheme_matrix(len, std::vector<size_t>(IN_v+1, 0));
        for(size_t i = 0; i != len; ++i){
            size_t weight = IN_weights[i];
            size_t value = IN_values[i];
            for(size_t j = weight; j <= IN_v; ++j){
                if(i){
                    if(scheme_matrix[i-1][j] < scheme_matrix[i-1][j - weight] + value)
                        scheme_matrix[i][j] = scheme_matrix[i-1][j - weight] + value;  
                }else{
                    scheme_matrix[i][j] = value;
                } 
            }
        }
        int num_idx = len - 1;
        int  weight_idx = IN_v;
        while(num_idx >= 0 && weight_idx > 0){
            size_t weight = IN_weights[num_idx];
            size_t value = IN_values[num_idx];
            if(num_idx){
                if(scheme_matrix[num_idx][weight_idx] != scheme_matrix[num_idx-1][weight_idx]){
                    OUT_scheme.push_back(num_idx + 1);
                    weight_idx -= weight;
                }else{
                    --num_idx;
                }
            }else{
                if(scheme_matrix[num_idx][weight_idx] == scheme_matrix[num_idx][weight_idx - weight] + value){
                    OUT_scheme.push_back(num_idx + 1);
                    weight_idx -= weight;
                }
            }
        }
        OUT_max = scheme_matrix[len - 1][IN_v];
    }
}