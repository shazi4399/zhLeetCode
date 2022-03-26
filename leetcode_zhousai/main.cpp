//
//  main.cpp
//  leetcode_zhousai
//
//  Created by zhanghao on 2022/3/13.
//

#include <iostream>
#include<vector>
#include<set>

using namespace std;
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> arr,ans;
        set<int> set;
        int n = nums.size();
        for(int i = 0; i < n;++i){
            if(nums[i] == key){
                int j =0;
                for(int j = i - k ; j <= i +k&& j <n ;j++){
                    if(j <0)
                        continue;
                    set.insert(j);
                }
            }
        }
        for(auto i : set){
            ans.push_back(i);
        }

        return ans;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int>arr = {3,4,9,1,3,9,5};
    vector<int> ans;
    Solution sol;
    ans = sol.findKDistantIndices(arr, 9, 1);
    for(auto i : ans){
        cout<<i;
    }
    return 0;
}
