/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-22 19:42:47 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-22 20:35:20
 */

 #include "../knapsack_problem.h"

namespace dynamic_programming{
    void knapsack_Problem::rely_knapsack_problem_scheme(size_t IN_v1, std::vector<std::vector<size_t> > IN_weights_2D, std::vector<std::vector<size_t> > IN_values_2D, std::vector<std::tuple<size_t, size_t> > &OUT_scheme, size_t &OUT_max)
    {
        size_t group_len = IN_weights_2D.size();
        std::vector<std::vector<size_t> > scheme_matrix(group_len, std::vector<size_t>(IN_v1 + 1, 0));
        for(size_t group_idx = 0; group_idx < group_len; ++group_idx){
            
            size_t items_len = IN_weights_2D[group_idx].size();
            size_t main_weight = IN_weights_2D[group_idx][0];
            size_t main_value = IN_values_2D[group_idx][0];

            std::vector<size_t> tmp_max_values;
            tmp_max_values = (group_idx? scheme_matrix[group_idx-1] : scheme_matrix[0]);
            for(size_t items_idx = 1; items_idx < items_len; ++items_idx){
                size_t weight = IN_weights_2D[group_idx][items_idx];
                size_t value = IN_values_2D[group_idx][items_idx];
                for(size_t weight_cursor = IN_v1; weight_cursor >= weight; --weight_cursor){
                    if(tmp_max_values[weight_cursor] < tmp_max_values[weight_cursor - weight] + value)
                        tmp_max_values[weight_cursor] = tmp_max_values[weight_cursor - weight] + value;
                }
            }

            for(size_t weight_cursor = IN_v1; weight_cursor >= main_weight; --weight_cursor){
                if(scheme_matrix[group_idx][weight_cursor] < tmp_max_values[weight_cursor - main_weight] + main_value)
                    scheme_matrix[group_idx][weight_cursor] = tmp_max_values[weight_cursor - main_weight] + main_value;
            }
        }

        int weight_cursor = IN_v1;
        int group_idx = group_len-1;
        while(group_idx >= 0 && weight_cursor > 0){
            size_t group_len = IN_weights_2D[group_idx].size();
            if(group_idx){
                for(size_t items_idx = 0; items_idx < group_len; ++items_idx){
                    if(scheme_matrix[group_idx][weight_cursor] != scheme_matrix[group_idx-1][weight_cursor]){
                        OUT_scheme.push_back(std::make_tuple(group_idx + 1, items_idx + 1));
                        weight_cursor -= IN_weights_2D[group_idx][items_idx];
                    }
                }
                --group_idx;
            }else{
                for(size_t items_idx = 0; items_idx < group_len; ++items_idx){
                    size_t weight = IN_weights_2D[group_idx][items_idx];
                    size_t value = IN_values_2D[group_idx][items_idx];
                    if(scheme_matrix[group_idx][weight_cursor] == scheme_matrix[group_idx][weight_cursor - weight] + value){
                        OUT_scheme.push_back(std::make_tuple(group_idx + 1, items_idx + 1));
                        weight_cursor -= weight;
                    }
                }
                --group_idx;              
            }
        }
        OUT_max = scheme_matrix[group_len-1][IN_v1];
    }
 }