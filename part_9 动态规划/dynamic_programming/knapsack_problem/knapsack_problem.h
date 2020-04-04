/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-19 22:16:30 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-22 20:26:43
 *
 //!背包问题头文件
 *
 */
#ifndef __KNAPSACK_PROBLEM_H__
#define __KNAPSACK_PROBLEM_H__

#include <tuple>
#include <vector>
#include <iostream>

namespace dynamic_programming{
    class knapsack_Problem{
        public:
        
        //* 1. 01背包问题，传入参数：背包容积（IN_v），物品体积向量(IN_weights), 物品的对应价值向量(IN_values)；传出参数：最大价值(OUT_max)
            static void _01_knapsack_problem(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values, size_t &OUT_max);

            //* 输出选择方案的算法实现
            static void _01_knapsack_problem_scheme(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values, std::vector<size_t> &OUT_scheme, size_t &OUT_max);

        //* 2. 完全背包问题，传入参数：背包容积（IN_v），物品体积向量(IN_weights), 物品的对应价值向量(IN_values)；传出参数：最大价值(OUT_max)
            static void complete_knapsack_problem(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values, size_t &OUT_max);

            //* 输出选择方案的算法实现
            static void complete_knapsack_problem_scheme(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values, std::vector<size_t> &OUT_scheme, size_t &OUT_max);

        //* 3. 二维背包问题，传入参数：背包限制条件1（IN_v1），背包限制条件2（IN_v2），物品限制条件向量1(IN_weights1), 物品限制条件向量2(IN_weights2), 物品的对应价值向量(IN_values)；传出参数：最大价值(OUT_max)
            static void _2D_knapsack_problem(size_t IN_v1,size_t IN_v2, std::vector<size_t> IN_weights1, std::vector<size_t> IN_weights2, std::vector<size_t> IN_values, size_t &OUT_max);

            //* 输出选择方案的算法实现
            static void _2D_knapsack_problem_scheme(size_t IN_v1, size_t IN_v2, std::vector<size_t> IN_weights1, std::vector<size_t> IN_weights2, std::vector<size_t> IN_values, std::vector<size_t> &OUT_scheme, size_t &OUT_max);
        
        //* 4. 分组背包问题，传入参数：背包容积（IN_v），物品体积向量(IN_weights_2D), 物品的对应价值向量(IN_values_2D)；传出参数：最大价值(OUT_max)
            static void group_knapsack_problem(size_t IN_v1, std::vector<std::vector<size_t> > IN_weights_2D, std::vector<std::vector<size_t> > IN_values_2D, size_t &OUT_max);

            //* 输出选择方案的算法实现
            static void group_knapsack_problem_scheme(size_t IN_v1, std::vector<std::vector<size_t> > IN_weights_2D, std::vector<std::vector<size_t> > IN_values_2D, std::vector<std::tuple<size_t, size_t> > &OUT_scheme, size_t &OUT_max);

        //* 5. 多重背包问题，传入参数：背包容积（IN_v），物品体积向量(IN_weights), 物品的对应价值向量(IN_values), 每件物品的数量向量（IN_nums）；传出参数：最大价值(OUT_max)
            static void multiple_knapsack_problem(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values,std::vector<size_t> IN_nums, size_t &OUT_max);
            
            //* 输出选择方案的算法实现
            static void multiple_knapsack_problem_scheme(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values,std::vector<size_t> IN_nums, std::vector<size_t> &OUT_scheme, size_t &OUT_max);

        //* 6. 混合背包问题，传入参数：背包容积（IN_v），物品体积向量(IN_weights), 物品的对应价值向量(IN_values), 每件物品的数量向量（IN_nums）；传出参数：最大价值(OUT_max)
            static void mix_knapsack_problem(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values,std::vector<size_t> IN_nums, size_t &OUT_max);
            
            //* 输出选择方案的算法实现
            static void mix_knapsack_problem_scheme(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values,std::vector<size_t> IN_nums, std::vector<size_t> OUT_scheme, size_t &OUT_max);

        //* 7. 有依赖关系的背包问题，传入参数：背包容积（IN_v），物品体积向量(IN_weights_2D), 物品的对应价值向量(IN_values_2D)；传出参数：最大价值(OUT_max)
            static void rely_knapsack_problem(size_t IN_v1, std::vector<std::vector<size_t> > IN_weights_2D, std::vector<std::vector<size_t> > IN_values_2D, size_t &OUT_max);

            //* 输出选择方案的算法实现
            static void rely_knapsack_problem_scheme(size_t IN_v1, std::vector<std::vector<size_t> > IN_weights_2D, std::vector<std::vector<size_t> > IN_values_2D, std::vector<std::tuple<size_t, size_t> > &OUT_scheme, size_t &OUT_max);

    };
}

#endif

