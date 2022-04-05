//
//  main.cpp
//  47
//
//  Created by zhanghao on 2022/4/5.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void backTrack(vector<int> & path,vector<bool> & visited,vector<int> & nums){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i = 0 ; i < nums.size();++i){
            //先判断是否访问过
            if(visited[i] == true || (i >= 1 && nums[i - 1] == nums[i] && !visited[i-1]))
                continue;
            //访问该元素
            visited[i] = true;
            path.push_back(nums[i]);
            //进入到下一个决策点
            backTrack(path,visited,nums);
            //撤销选择
            visited[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        vector<bool> visited(nums.size(),false);
        sort(nums.begin(),nums.end());
        backTrack(path,visited,nums);
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    vector<vector<int>> ans;
    vector<int> nums = {1,1,2};
    ans = Solution().permuteUnique(nums);
    for(auto i :ans){
        for(auto j:i){
            cout<< j <<" ";
        }
        cout<<endl;
    }
    return 0;
}
