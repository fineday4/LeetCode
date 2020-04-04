# 背包问题全解
## 目录及文件结构：
    |
    |---> test.cc(测试程序)
    |---> knapsack_problem_max_value(存放背包问题求最优值算法的文件的文件夹)
            |---> _01_knapsack_problem.h(01背包)
            |---> _2D_knapsack_problem.h(二维背包)
            |---> complete_knapsack_problem.h(完全背包)
            |---> group_knapsack_problem.h(分组背包)
            |---> mix_knapsack_problem.h(混合背包)
            |---> multiple_knapsack_problem.h(多重背包)
            |---> rely_knapsack_problem.h(有依赖关系的背包)
    |---> knapsack_problem_scheme(存放背包问题求最优值和最优值取得方案算法的文件的文件夹)
            |---> _01_knapsack_problem_scheme.h(01背包)
            |---> _2D_knapsack_problem_scheme.h(二维背包)
            |---> complete_knapsack_problem_scheme.h(完全背包)
            |---> group_knapsack_problem_scheme.h(分组背包)
            |---> mix_knapsack_problem_scheme.h(混合背包)
            |---> multiple_knapsack_problem_scheme.h(多重背包)
            |---> rely_knapsack_problem_scheme.h(有依赖关系的背包)
    |---> knapsack_problem.h(背包问题头文件)
    |---> README.md(该算法包的基本说明)
    编译指令：g++ test.cc -std=c++11
## 求解思想核心
    背包问题的核心就是————状态转移方程：f[item_idx][weight_cursor] = max{f[item_idx-1][weight_cursor], f[item_idx-1][weight_cursor-weights[item_idx]] + values[item_idx]}，
    其中f[item_idx][weight_cursor]为前item_idx个物品，在重量为weight_cursor时的最大价值，weights[item_idx]表示第item_idx个物品的重量， values[item_idx]表示第item_idx个物品的
    价值，所以上述状态转移方程可以理解为，前item_idx个物品在限制最大重量为weight_cursor时的最大价值是“前item_idx-1个物品在限制最大重量为weight_cursor时的最大价值与前item_idx-1个
    物品在限制最大重量为weight_cursor-weight[item_idx]时的最大价值加上第item_idx个物品的价值的较大者”;只要理解了这个方程，就可以依据不同的限制条件，实现不同的算法。因为限制条件的各
    异所以才有了各类的背包问题，如：01背包，完全背包，2维背包，多重背包，混合背包，分组背包，有依赖关系的背包等等。本算法包就依据状态转移方程实现了上述的7中背包算法。
### 1.01背包
### 2.完全背包
### 3.2维背包
### 4.多重背包
### 5.混合背包
### 6.分组背包
### 7.有依赖关系的背包
