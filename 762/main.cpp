//
//  main.cpp
//  762
//
//  Created by zhanghao on 2022/4/5.
//762. 二进制表示中质数个计算置位

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPrimer(int n ){
        if(n == 1) return false;
        if(n == 2) return true;
        for(int i = 2 ; i <= n/2;++i){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {

        int ans = 0;
        for(int i = left ; i <= right; ++i){
            int temp = i;
            int count = 0;
            while(temp > 0){
                if(temp&1){
                    count++;
                }
                temp = temp>>1;
            }
            if(isPrimer(count)){
                ans++;
            }
        }
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    int ans = Solution().countPrimeSetBits(10, 15);
    cout<<ans<<endl;
    return 0;
}
