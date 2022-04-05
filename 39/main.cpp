//
//  main.cpp
//  39
//
//  Created by zhanghao on 2022/4/5.
//https://leetcode-cn.com/problems/combination-sum/
//39 组合总和

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void backTrack(vector<int> &path,int & pathSum,vector<int>& candidates,int & target,int startIndex){
        if(pathSum == target){
            ans.push_back(path);
            return;
        }
        if(pathSum > target ){
            return;
        }
        for(int i = startIndex ; i < candidates.size();++i){
            //判断能不能选取此元素
            //选择此元素
            pathSum += candidates[i];
            path.push_back(candidates[i]);
            //进入下一层决策点
            backTrack(path,pathSum,candidates,target,i);//不用i + 1,表示可以重复读取当前的元素。
            //撤销选择的元素
            pathSum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        int pathSum = 0;
        //vector<bool> visited(candidates.size(),false);//不需要这个标记数组了。
        backTrack(path,pathSum,candidates,target,0);
        return ans;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> arr = {2,3,6,7};
    vector<vector<int>> ans = Solution().combinationSum(arr, 7);
    for(auto i:ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
