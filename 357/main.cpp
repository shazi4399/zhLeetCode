//
//  main.cpp
//  357
//
//  Created by zhanghao on 2022/4/11.
//357. 统计各位数字都不同的数字个数
//给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10n 。
//https://leetcode-cn.com/problems/count-numbers-with-unique-digits/


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits1(int n) {
        int ans = 0;
        unordered_map<int, int > mymap;
        if(n == 0)return 1;
        for(int i =0 ;i < pow(10,n);i++){
            //cout<< i<<endl;
            bool flag = true;
            int temp = i;
            mymap.clear();
            
            while(temp > 0){
                if(mymap[temp%10] != 0){
                    flag = 0;
                    cout<< i <<endl;
                    break;
                }
                mymap[temp % 10]++;
                temp /= 10;
            }
            if(flag) {
                ans++;
            }
        }
        return ans;
    }
    
    int countNumbersWithUniqueDigits2(int n){
        if(n == 0) return 1;
        int ans = 10;
        for(int i = 2,last = 9 ; i <= n;++i){
            //for(int j = 0 ; j < )
            int cur = last * (10 - i + 1);
            ans += cur;
            last = cur;
        }
        return ans;
    }
  
    int countNumbersWithUniqueDigits(int n) {
            if (n == 0) return 1;
            int ans = 10;
            for (int i = 2, last = 9; i <= n; i++) {
                int cur = last * (10 - i + 1);
                ans += cur;
                last = cur;
            }
            return ans;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int ans = Solution().countNumbersWithUniqueDigits(2);
    cout<< ans <<endl;
    return 0;
}
