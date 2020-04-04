/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-19 22:57:58 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-22 20:33:05
 */
 
#include "./knapsack_problem_max_value/_01_knapsack_problem.h"
#include "./knapsack_problem_max_value/_2D_knapsack_problem.h"
#include "./knapsack_problem_max_value/complete_knapsack_problem.h"
#include "./knapsack_problem_max_value/group_knapsack_problem.h"
#include "./knapsack_problem_max_value/mix_knapsack_problem.h"
#include "./knapsack_problem_max_value/multiple_knapsack_problem.h"
#include "./knapsack_problem_max_value/rely_knapsack_problem.h"


#include "./knapsack_problem_scheme/_01_knapsack_problem_scheme.h"
#include "./knapsack_problem_scheme/_2D_knapsack_problem_scheme.h"
#include "./knapsack_problem_scheme/complete_knapsack_problem_scheme.h"
#include "./knapsack_problem_scheme/group_knapsack_problem_scheme.h"
#include "./knapsack_problem_scheme/mix_knapsack_problem_scheme.h"
#include "./knapsack_problem_scheme/multiple_knapsack_problem_scheme.h"
#include "./knapsack_problem_scheme/rely_knapsack_problem_scheme.h"

using namespace dynamic_programming;

int main()
{
#if 0  //! _01_knapsack_problem.cc测试
    size_t IN_v = 5;
    std::vector<size_t> IN_weights{5,4,3,2,1};
    std::vector<size_t> IN_values{1,2,3,4,5};
    size_t OUT_max;
    knapsack_Problem::_01_knapsack_problem(IN_v, IN_weights, IN_values, OUT_max);
    std::cout << OUT_max << std::endl;
#endif

# if 0 //! _01_knapsack_problem_scheme.cc
    size_t IN_v = 5;
    std::vector<size_t> IN_weights{5,4,3,2,1};
    std::vector<size_t> IN_values{1,2,3,4,5};
    size_t OUT_max;
    std::vector<size_t> OUT_scheme;
    knapsack_Problem::_01_knapsack_problem_scheme(IN_v, IN_weights, IN_values, OUT_scheme, OUT_max);
    for(auto i : OUT_scheme){
        std::cout << "select : " << i << " ";
    }
    std::cout << std::endl;
    std::cout << OUT_max << std::endl;
# endif

#if 0 //! complete_knapsack_problem.cc
    size_t IN_v = 5;
    std::vector<size_t> IN_weights{5,4,3,2,1};
    std::vector<size_t> IN_values{1,2,3,4,5};
    size_t OUT_max;
    knapsack_Problem::complete_knapsack_problem(IN_v, IN_weights, IN_values, OUT_max);
    std::cout << OUT_max << std::endl;
#endif

#if 0 //! complete_knapsack_problem_scheme.cc
    size_t IN_v = 5;
    std::vector<size_t> IN_weights{5,4,3,2,1};
    std::vector<size_t> IN_values{1,2,3,4,5};
    size_t OUT_max;
    std::vector<size_t> OUT_scheme;
    knapsack_Problem::complete_knapsack_problem_scheme(IN_v, IN_weights, IN_values, OUT_scheme, OUT_max);
    for(auto i : OUT_scheme){
        std::cout << "select : " << i << " ";
    }
    std::cout << std::endl;
    std::cout << OUT_max << std::endl;
#endif

#if 0 //! _2D_knapsack_problem.cc
    size_t IN_v1 = 5;
    size_t IN_v2 = 5;
    std::vector<size_t> IN_weights1{5,4,3,2,1};
    std::vector<size_t> IN_weights2{5,4,3,2,5};
    std::vector<size_t>   IN_values{1,2,3,4,5};
    size_t OUT_max;
    knapsack_Problem::_2D_knapsack_problem(IN_v1, IN_v2, IN_weights1, IN_weights2, IN_values, OUT_max);
    std::cout << OUT_max << std::endl;
#endif

#if 0 //! _2D_knapsack_problem_scheme.cc
    size_t IN_v1 = 5;
    size_t IN_v2 = 5;
    std::vector<size_t> IN_weights1{5,4,3,2,1};
    std::vector<size_t> IN_weights2{5,4,3,2,5};
    std::vector<size_t>   IN_values{1,2,3,4,5};
    size_t OUT_max;
    std::vector<size_t> OUT_scheme;
    knapsack_Problem::_2D_knapsack_problem_scheme(IN_v1, IN_v2, IN_weights1, IN_weights2, IN_values, OUT_scheme, OUT_max);
    for(auto i : OUT_scheme){
        std::cout << "XXselect : " << i << " ";
    }
    std::cout << std::endl;
    std::cout << OUT_max << std::endl;
#endif

#if 0 //! group_knapsack_problem.cc
//*未测试

#endif

#if 0 //! group_knapsack_problem_scheme.cc
//*未测试

#endif

#if 0 //! multiple_knapsack_problem.cc

#endif

#if 0 //! multiple_knapsack_problem_scheme.cc

#endif

}