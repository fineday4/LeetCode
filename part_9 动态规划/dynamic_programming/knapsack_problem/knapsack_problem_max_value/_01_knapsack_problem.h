/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-19 22:36:49 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-21 21:20:37
 *
 //!01背包问题实现源码
 *
 */

 #include "../knapsack_problem.h"
 
namespace dynamic_programming{
    void knapsack_Problem::_01_knapsack_problem(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values, size_t &OUT_max)
    {
        std::vector<size_t> max_values(IN_v+1, 0);
        size_t len = IN_weights.size();
        for(size_t i = 0; i != len; ++i){
            size_t weight = IN_weights[i];
            size_t value = IN_values[i];
            for(size_t j = IN_v; j >= weight; --j){
                if(max_values[j] < max_values[j - weight] + value)
                    max_values[j] = max_values[j - weight] + value;
            }
        }
        OUT_max = max_values[IN_v];
    }

}
