#include <vector>
#include <iostream>

using namespace std;

int main(){
    //!素数表的创建
    vector<bool> isprime(80000,true);
    isprime[0]=isprime[1]=false;
    for(int i=4;i<80000;i+=2)isprime[i]=false;  //*先把偶数值为false
    for(int i=3;i*i<80000;i+=2)//*所有的奇数
        if(isprime[i]){
            for(int j=i*i;j<80000;j+=2*i) isprime[j]=false;
        }
    for(size_t idx = 0; idx < 40; ++idx)
        cout << " idx: " << idx << " is primer: " << isprime[idx] << endl;

    return 0;
}