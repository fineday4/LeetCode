/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-20 16:01:23 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-21 21:39:31
 */

 #include "../knapsack_problem.h"
 
namespace dynamic_programming{
    void knapsack_Problem::_2D_knapsack_problem_scheme(size_t IN_v1, size_t IN_v2, std::vector<size_t> IN_weights1, std::vector<size_t> IN_weights2, std::vector<size_t> IN_values, std::vector<size_t> &OUT_scheme, size_t &OUT_max)
    {
        size_t len = IN_weights1.size();
        std::vector<std::vector<std::vector<size_t> > > scheme_matrix(len, std::vector<std::vector<size_t> >(IN_v1 + 1, std::vector<size_t>(IN_v2 + 1, 0)));
        for(size_t i = 0; i != len; ++i){
            size_t weight1 = IN_weights1[i];
            size_t weight2 = IN_weights2[i];
            size_t value = IN_values[i];
            for(size_t idx = IN_v1; idx >= weight1; --idx)
                for(size_t iidx = IN_v2; iidx >= weight2; --iidx)
                    if(i){
                        if(scheme_matrix[i-1][idx][iidx] < scheme_matrix[i-1][idx - weight1][iidx - weight2] + value)
                            scheme_matrix[i][idx][iidx] = scheme_matrix[i-1][idx - weight1][iidx - weight2] + value;
                        else
                            scheme_matrix[i][idx][iidx] = scheme_matrix[i - 1][idx][iidx];
                    }else{
                        scheme_matrix[i][idx][iidx] = value;
                    }
        }
        int weight1 = IN_v1;
        int weight2 = IN_v2;
        int idx = len -1;
        while(idx > 0 && weight2 > 0 && weight1 > 0){
            size_t value = IN_values[idx];
            if(idx){
                if(scheme_matrix[idx][weight1][weight2] != scheme_matrix[idx -1][weight1][weight2]){
                    OUT_scheme.push_back(idx +1);
                    std::cout << "idx: " << idx << std::endl;
                    weight1 -= IN_weights1[idx];
                    weight2 -= IN_weights2[idx];
                }
                --idx;
            }else{
                if(scheme_matrix[idx][weight1][weight2] == value){
                    OUT_scheme.push_back(idx + 1);
                    --idx;
                    weight1 -= IN_weights1[idx];
                    weight2 -= IN_weights2[idx];
                }
            }
        }
        OUT_max = scheme_matrix[len - 1][IN_v1][IN_v2];
    }
}