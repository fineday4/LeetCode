/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-21 22:19:10 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-21 22:48:39
 */

/*
 * @Author: xuhuanhuan 
 * @Date: 2020-02-21 22:05:47 
 * @Last Modified by: xuhuanhuan
 * @Last Modified time: 2020-02-21 22:18:51
 *
 *混合背包 = 01背包 + 完全背包 + 多重背包
 *
 */

 #include "../knapsack_problem.h"

 namespace dynamic_programming{
     void knapsack_Problem::mix_knapsack_problem_scheme(size_t IN_v, std::vector<size_t> IN_weights, std::vector<size_t> IN_values,std::vector<size_t> IN_nums, std::vector<size_t> OUT_scheme, size_t &OUT_max)
     {
         size_t len = IN_weights.size();
         std::vector<std::vector<size_t> > scheme_matrix(len, std::vector<size_t>(IN_v+1, 0));
         for(size_t item_idx = 0; item_idx < len; ++item_idx){
             size_t value = IN_values[item_idx];
             size_t weight = IN_weights[item_idx];
             size_t item_num = IN_nums[item_idx];
            if(item_num){
                //01背包( i == 1) & 多重背包(i > 1)
                for(size_t iitem_num = 0; iitem_num < item_num; ++iitem_num){
                    for(size_t weight_cursor = IN_v; weight_cursor >= weight; --weight_cursor){
                        if(item_idx){
                            if(scheme_matrix[item_idx-1][weight_cursor] < scheme_matrix[item_idx-1][weight_cursor-weight] + value)
                                scheme_matrix[item_idx][weight_cursor] = scheme_matrix[item_idx-1][weight_cursor-weight] + value;
                            else
                                scheme_matrix[item_idx][weight_cursor] = scheme_matrix[item_idx-1][weight_cursor];
                        }else{
                            if(scheme_matrix[item_idx][weight_cursor] < scheme_matrix[item_idx][weight_cursor-weight] + value)
                                scheme_matrix[item_idx][weight_cursor] < scheme_matrix[item_idx][weight_cursor-weight] + value;
                        }
                    }
                }
            }else{
                //完全背包(i == 0)
                for(size_t weight_cursor = weight; weight_cursor <= IN_v; ++weight_cursor){
                    if(item_idx){
                    if(scheme_matrix[item_idx-1][weight_cursor] < scheme_matrix[item_idx-1][weight_cursor-weight] + value)
                        scheme_matrix[item_idx][weight_cursor] = scheme_matrix[item_idx-1][weight_cursor-weight] + value;
                    else
                        scheme_matrix[item_idx][weight_cursor] = scheme_matrix[item_idx-1][weight_cursor];
                }else{
                    if(scheme_matrix[item_idx][weight_cursor] < scheme_matrix[item_idx][weight_cursor-weight] + value)
                        scheme_matrix[item_idx][weight_cursor] < scheme_matrix[item_idx][weight_cursor-weight] + value;
                }
                }
            }

                 
         }

         
         int item_idx = len -1;
         int weight_cursor = IN_v;
         while(item_idx >= 0 && weight_cursor > 0){
             size_t weight = IN_weights[item_idx];
             size_t value = IN_values[item_idx];
             size_t flag = IN_nums[item_idx];
             if(flag){
                 if(flag == 1){//01背包
                    if(item_idx){
                        if(scheme_matrix[item_idx][weight_cursor] != scheme_matrix[item_idx-1][weight_cursor]){
                            OUT_scheme.push_back(item_idx + 1);
                            weight_cursor -= weight;
                        }
                        --item_idx;
                    }else{
                        if(scheme_matrix[item_idx][weight_cursor] == value){
                            OUT_scheme.push_back(item_idx + 1);
                            weight_cursor -= weight;
                        }
                        --item_idx;
                    } 
                 }else{//多重背包
                    if(item_idx){
                        if(scheme_matrix[item_idx][weight_cursor] != scheme_matrix[item_idx-1][weight_cursor]){
                            OUT_scheme.push_back(item_idx+1);
                            weight_cursor -= weight;
                        }else{
                            --item_idx;
                        }
                    }else{
                        if(scheme_matrix[item_idx][weight_cursor] == scheme_matrix[item_idx][weight_cursor-weight] + value){
                            OUT_scheme.push_back(item_idx + 1);
                            weight_cursor -= weight;
                        }else{
                            --item_idx;
                        }
                    }
                 }
             }else{//完全背包
                    if(item_idx){
                        if(scheme_matrix[item_idx][weight_cursor] != scheme_matrix[item_idx-1][weight_cursor]){
                            OUT_scheme.push_back(item_idx+1);
                            weight_cursor -= weight;
                        }else{
                            --item_idx;
                        }
                    }else{
                        if(scheme_matrix[item_idx][weight_cursor] == scheme_matrix[item_idx][weight_cursor-weight] + value){
                            OUT_scheme.push_back(item_idx + 1);
                            weight_cursor -= weight;
                        }else{
                            --item_idx;
                        }
                    }                 
             }
         }
         OUT_max = scheme_matrix[len-1][IN_v];
         
     }
 }
