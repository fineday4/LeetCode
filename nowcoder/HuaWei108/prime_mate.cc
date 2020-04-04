/*
 * @Author: toraoh(牛客大佬) 
 * @Date: 2020-02-28 10:40:55 
 * @Last Modified time: 2020-02-28 10:41:20
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
 
vector<int> G[105];
 
bool flag[105];  //* flag[x]的作用是标记下标为x的元素已经被使用过了
int pre[105]; //* pre[x]=k的作用是标记偶数下标x的素数伴侣的下标k.
 
bool dfs(int k){  //* nums[k]是否能够配成素数伴侣
    int x;
    for(int i=0;i<G[k].size();i++){
        x=G[k][i];//* nums[k]是奇数，它的第i个素数伴侣的下标为x
        if (flag[x]) continue;
        flag[x]=true;
        if((pre[x]==0)||dfs(pre[x])){
            pre[x]=k;
            return true;
        }
    }
    return false;
}
 
bool isprime[80000];
int nums[105];
 
int main(){
    //!素数表的创建
    memset(isprime,1,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=4;i<80000;i+=2)isprime[i]=false;
    for(int i=3;i*i<80000;i+=2)
        if(isprime[i]){
            for(int j=i*i;j<80000;j+=2*i) isprime[j]=false;
        }
    //*------------------
    int n;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&nums[i]);
        }
        //! 求和取质
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                if(isprime[nums[i]+nums[j]]){
                    (nums[i]&1)?G[i].push_back(j):G[j].push_back(i);//? 这个是什么操作？？？ num[i]&1？当num[i]为偶数时=0，就会向G[j](num[j]必为奇数)push 偶数下标i. 为奇数时=1，就会一直向G[i]中push偶数的小标j。
                    //? 所以G的第一维是奇数的下标，第二维是偶数下标。
                }
            }
        }
 //! 贪心算法
        memset(pre,0,sizeof(pre));
        int ans=0;
        for(int i=1;i<=n;i++){
            memset(flag,false,sizeof(flag));
            if (dfs(i)) ans++;
        }
        printf("%d\n",ans);
         
        for(int i=1;i<=n;++i){
            G[i].clear();
        }
    }
    return 0;
}