/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-20 16:01:23 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-21 21:20:52
 */

 #include "../knapsack_problem.h"
 
namespace dynamic_programming{
    void knapsack_Problem::_2D_knapsack_problem(size_t IN_v1,size_t IN_v2, std::vector<size_t> IN_weights1, std::vector<size_t> IN_weights2, std::vector<size_t> IN_values, size_t &OUT_max)
    {
        size_t len = IN_weights1.size();
        std::vector<std::vector<size_t> > max_values_matrix(IN_v1 + 1, std::vector<size_t>(IN_v2 + 1, 0));
        for(size_t i = 0; i != len; ++i){
            size_t weight1 = IN_weights1[i];
            size_t weight2 = IN_weights2[i];
            size_t value = IN_values[i];
            for(size_t idx = IN_v1; idx >= weight1; --idx){
                for(size_t iidx = IN_v2; iidx >= weight2; --iidx){
                    if(max_values_matrix[idx][iidx] < max_values_matrix[idx - weight1][iidx - weight2] + value)
                        max_values_matrix[idx][iidx] = max_values_matrix[idx - weight1][iidx - weight2] + value;
                }
            }
        }
        OUT_max = max_values_matrix[IN_v1][IN_v2];
    }
}