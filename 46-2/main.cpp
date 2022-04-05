//
//  main.cpp
//  46-2
//
//  Created by zhanghao on 2022/4/5.
//

//
//  main.cpp
//  46permute
//
//  Created by zhanghao on 2022/4/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void backTrack(vector<vector<int>>& ans,vector<int> & path,vector<int>& nums,vector<bool> & visted){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        //多叉树的遍历，决策树
        for(int i = 0; i < nums.size();i++){
            //排除已经遍历过的
            if(visted[i] == true)
                continue;
            //选择此元素
            visted[i] = true;//选择它
            path.push_back(nums[i]);//选择它
            //进入决策树的下一层（进入到下一个选择）
            backTrack(ans, path, nums, visted);
            //取消选择（回溯的思想）
            path.pop_back();
            visted[i] = false;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> visted(nums.size(),false);
        backTrack(ans, path, nums, visted);
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans = Solution().permute(arr);
    for(auto  i : ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
