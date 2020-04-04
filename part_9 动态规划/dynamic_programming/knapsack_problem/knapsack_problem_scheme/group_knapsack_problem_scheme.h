/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-21 15:47:12 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-22 20:28:12
 */
#include"../knapsack_problem.h"

namespace  dynamic_programming{
    void knapsack_Problem::group_knapsack_problem_scheme(size_t IN_v1, std::vector<std::vector<size_t> > IN_weights_2D, std::vector<std::vector<size_t> > IN_values_2D, std::vector<std::tuple<size_t, size_t> > &OUT_scheme, size_t &OUT_max)
    {
        size_t len = IN_weights_2D.size();
        std::vector<std::vector<size_t> > scheme_matrix(len, std::vector<size_t>(IN_v1+1, 0));
        for(size_t group_idx = 0; group_idx < len; ++group_idx){
            size_t ilen = IN_weights_2D[group_idx].size();
            std::vector<size_t> max_value(IN_v1 + 1, 0);
            for(size_t item_idx = 0; item_idx < ilen; ++item_idx){
                size_t weight = IN_weights_2D[group_idx][item_idx];
                size_t value = IN_values_2D[group_idx][item_idx];
                for(size_t weight_idx = IN_v1; weight_idx >= weight; --weight_idx){
                    if(max_value[weight_idx] < value)
                        max_value[weight_idx] = value;
                }
            }
            for(size_t weight_idx = IN_v1; weight_idx > 0; --weight_idx){
                for(size_t weight_iidx = weight_idx; weight_iidx >= 0; --weight_iidx){
                    if(scheme_matrix[group_idx][weight_idx] < scheme_matrix[group_idx][weight_idx - weight_iidx] + max_value[weight_iidx])
                        scheme_matrix[group_idx][weight_idx] = scheme_matrix[group_idx][weight_idx - weight_iidx] + max_value[weight_iidx];
                }
            }
        }
        int weight_idx = IN_v1;
        int group_idx = len -1;
        while(group_idx >= 0 && weight_idx > 0){
            size_t group_len = IN_weights_2D[group_idx].size();
            for(size_t item_idx = 0; item_idx < group_len; ++item_idx){
                size_t weight = IN_weights_2D[group_idx][item_idx];
                size_t value = IN_values_2D[group_idx][item_idx];
                if(group_idx && weight_idx >= weight){
                    if(scheme_matrix[group_idx][weight_idx] == scheme_matrix[group_idx - 1][weight_idx - weight] + value){
                        weight_idx -= weight;
                        OUT_scheme.push_back(std::make_tuple(group_idx+1, item_idx + 1));
                    }
                }else if(group_idx == 0){
                    if(scheme_matrix[group_idx][weight_idx] == value){
                        weight_idx -= weight;
                        OUT_scheme.push_back(std::make_tuple(group_idx+1, item_idx + 1));
                    }
                }
            }
            --group_idx;
        }
        OUT_max = scheme_matrix[len-1][IN_v1];
    }
}
