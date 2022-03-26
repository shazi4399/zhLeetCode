//
//  main.cpp
//  172
//
//  Created by zhanghao on 2022/3/25.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int jiecheng(int n ){
        if(n == 1 || n == 0 )
            return 1;
        return n*jiecheng(n - 1 );
    }
    int trailingZeroes(int n) {
        int sum = jiecheng(n);
        int count = 0;
        while(sum % 10 == 0){
            count++;
            sum = sum / 10;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution sol;
    int ans = sol.trailingZeroes(3);
    cout<<ans<<endl;;
    return 0;
}
