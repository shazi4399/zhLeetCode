//
//  main.cpp
//  954
//
//  Created by zhanghao on 2022/4/1.
// 954. 二倍数对数组

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        unordered_map<int, int> cnt;
        for (int x : arr) {
            ++cnt[x];
        }
        if (cnt[0] % 2) {
            return false;
        }

        vector<int> vals;
        vals.reserve(cnt.size());
        for (auto &[x, _] : cnt) {
            vals.push_back(x);
        }
        sort(vals.begin(), vals.end(), [](int a, int b) { return abs(a) < abs(b); });

        for (int x : vals) {
            if (cnt[2 * x] < cnt[x]) { // 无法找到足够的 2x 与 x 配对
                return false;
            }
            cnt[2 * x] -= cnt[x];
        }
        return true;
    }
};


int main(int argc, const char * argv[]) {
    vector<int>arr = {4,-2,2,-4};
    bool flag = Solution().canReorderDoubled(arr);
    cout<<flag<<endl;
    return 0;
}
