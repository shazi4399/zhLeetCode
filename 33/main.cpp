//
//  main.cpp
//  33
//
//  Created by zhanghao on 2022/3/28.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums,int left,int right){
        while(left < right){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
    int search(vector<int>& nums, int target) {
        //int mid = 0;
        int left = 0,right = nums.size()-1;
//        while(left < right){
//            mid = left + (right-left)/2;
//            if(nums[mid]<nums[mid+1] && nums[mid-1]>nums[mid]){
//                break;
//            }else if(nums[mid] > nums[mid+1] ){
//                left = mid + 1;
//            }else if(nums[mid - 1] < nums[mid] ){
//                left = mid + 1;
//            }
//        }
        int i = 0;
        for(; i <nums.size()-1;++i){
            if(i>=1&& nums[i-1]>nums[i] && nums[i] < nums[i+1]){
                break;
            }
            
        }
        reverse(nums,0,i-1);
        reverse(nums,i,nums.size()-1);
        reverse(nums,0,nums.size()-1);
        int mid2 = 0;
        while(left <= right){
            mid2 = left+(right - left)/2;
            if(nums[mid2] == target){
                return mid2 + i;
            }else if(nums[mid2] > target ){
                right = mid2 -1;
            }else{
                left = mid2 + 1;
            }
        }
        return -1;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arr={4,5,6,7,0,1,2};
    int ans = Solution().search(arr, 0);
    cout<<ans<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
