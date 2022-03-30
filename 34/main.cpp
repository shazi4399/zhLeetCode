//
//  main.cpp
//  34
//
//  Created by zhanghao on 2022/3/30.
//  34. 在排序数组中查找元素的第一个和最后一个位置

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //左边界二分模版
    int binarySearchLeftBound(vector<int> & nums,int target){
        int left = 0 ,right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] >= target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        // 考虑目标值不在数组中的两种情况
        if (left == nums.size() || nums[left] != target) left = -1;
        return left;
    }
    //右边界二分模版
    int binarySearchRightBound(vector<int> & nums ,int target ){
        int left = 0,right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] <= target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        // 考虑目标值不在数组中的两种情况
        if(right == -1 || nums[right] != target  ) right = -1;
        return right;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = binarySearchLeftBound(nums,target);
        int right = binarySearchRightBound(nums,target);
        return  {left, right};
    }
};


int main(int argc, const char * argv[]) {
    vector<int> arr= {5,7,7,8,8,10};
    vector<int> ans = Solution().searchRange(arr, 8);
    for(auto & i : ans){
        cout<<i<<endl;
    }
    return 0;
}
