//
//  main.cpp
//  40
//
//  Created by zhanghao on 2022/4/5.
//40. 组合总和 II
//https://leetcode-cn.com/problems/combination-sum-ii/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void backTrack(vector<int> &path,int & pathSum,vector<int>& candidates,int & target,int startIndex,vector<bool> & visited){
        if(pathSum == target){
            ans.push_back(path);
            return;
        }
        if(pathSum > target ){
            return;
        }
        for(int i = startIndex ; i < candidates.size();++i){
            //判断能不能选取此元素
            if(i>0 && candidates[i] == candidates[i-1] && visited[i-1] == false)continue;
            //选择此元素
            visited[i] = true;
            pathSum += candidates[i];
            path.push_back(candidates[i]);
            //进入下一层决策点
            backTrack(path,pathSum,candidates,target,i+1,visited);//不用i + 1,表示可以重复读取当前的元素。
            //撤销选择的元素
            pathSum -= candidates[i];
            path.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        vector<bool> visited(candidates.size(),false);
        int pathSum = 0;
        sort(candidates.begin(),candidates.end());
        backTrack(path,pathSum,candidates,target,0,visited);
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    vector<vector<int>> arr;
    vector<int> num = {10,1,2,7,6,1,5};
    arr = Solution().combinationSum2(num, 8);
    for(auto i:arr){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
