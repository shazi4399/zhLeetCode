//
//  main.cpp
//  283
//
//  Created by zhanghao on 2022/3/26.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0,right = 0 ;
        while(right < n){
            if(nums[right] != 0){
                swap(nums[left],nums[right]);
                left++;
            }
            right++;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> arr = {0,1,0,3,12};
    Solution().moveZeroes(arr);
    for(auto & i:arr){
        cout<<i<<" ";
    }
    return 0;
}
