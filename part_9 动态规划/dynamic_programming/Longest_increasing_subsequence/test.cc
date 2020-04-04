/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-26 21:44:30 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-26 22:17:25
 */

#include "dynamic_longest_sub.h"
#include "dynamic_longest_sub_scheme.h"

using namespace dynamic_programming;

int main()
{
#if 0 //dynamic_longest_sub.h 测试
    std::vector<int> vec{4,2,3,1,5};
    int max;
    longest_in_sub::dynamic_longest_sub(vec, max);
    std::cout << "max(should be 3) is : " << max << std::endl;
#endif
    std::vector<int> vec{1,2,3,1,5};
    std::vector<int> OUT_max_scheme;
    longest_in_sub::dynamic_longest_sub_scheme(vec, OUT_max_scheme);
    for(auto i : OUT_max_scheme)
        std::cout << i << " ";
    std::cout << std::endl;
    
    return 0;
}