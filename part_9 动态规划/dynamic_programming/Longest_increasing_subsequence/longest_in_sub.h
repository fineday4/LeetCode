/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-26 21:23:21 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-26 21:49:10
 */
#ifndef __LONGEST_IN_SUB_H__
#define __LONGEST_IN_SUB_H__

#include <iostream>
#include <vector>
#include <algorithm>

namespace dynamic_programming{
    class longest_in_sub{
        public:
            static void dynamic_longest_sub(const std::vector<int> &IN_vec, int &OUT_max);
            static void dynamic_longest_sub_scheme(const std::vector<int> &IN_vec, std::vector<int> &OUT_max_scheme);
    };
}
#endif