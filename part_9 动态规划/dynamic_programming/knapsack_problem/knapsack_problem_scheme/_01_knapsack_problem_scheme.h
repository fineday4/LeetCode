/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-19 23:06:40 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-21 22:03:05
 */

#include "../knapsack_problem.h"

namespace dynamic_programming{
    void knapsack_Problem::_01_knapsack_problem_scheme(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values, std::vector<size_t> &OUT_scheme, size_t &OUT_max)
    {
        size_t len = IN_weights.size();
        std::vector<std::vector<size_t> > scheme_matrix(len, std::vector<size_t>(IN_v+1, 0));
        for(size_t i = 0; i != len; ++i){
            size_t weight = IN_weights[i];
            size_t value = IN_values[i];
            for(size_t j = IN_v; j >= weight; --j){
                if(i){
                    if(scheme_matrix[i-1][j] < scheme_matrix[i-1][j - weight] + value)
                        scheme_matrix[i][j] = scheme_matrix[i-1][j - weight] + value;
                    else
                        scheme_matrix[i][j] = scheme_matrix[i-1][j];
                }else{
                    scheme_matrix[i][j] = value;
                }
            }
        }
        int i = len-1;
        int j = IN_v;
        while(j > 0 && i >= 0){
            if(i){
                if(scheme_matrix[i][j] != scheme_matrix[i-1][j]){
                    OUT_scheme.push_back(i+1);
                    j -= IN_weights[i];
                }
                --i;
            }else{
                if(scheme_matrix[i][j] == IN_values[i])
                    OUT_scheme.push_back(i+1);
                    j -= IN_weights[i];
                    --j;
            }
        }
        OUT_max = scheme_matrix[len-1][IN_v];
    }
}