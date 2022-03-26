//
//  main.cpp
//  440
//
//  Created by zhanghao on 2022/3/23.
//

#include <iostream>
using namespace std;

class Solution {
public:
    long getCount(long prefix, long n) {
        long cur = prefix;
        long next = cur + 1;
        long count = 0;
        while(cur <= n) {
            count += min(n+1, next) - cur;
            cur *= 10;
            next *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        long p = 1;
        long prefix = 1;
        while(p < k) {
            long count = getCount(prefix, n);
            if (p + count > k) {
                /// 说明第k个数，在这个前缀范围里面
                prefix *= 10;
                p++;
            } else if (p+count <= k) {
                /// 说明第k个数，不在这个前缀范围里面，前缀需要扩大+1
                prefix++;
                p += count;
            }
        }
        return static_cast<int>(prefix);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    Solution sol;
    int ans = sol.findKthNumber(13, 4);
    cout<< ans<<endl;
    return 0;
}
