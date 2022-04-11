//
//  main.cpp
//  784
//
//  Created by zhanghao on 2022/4/5.
//784. 字母大小写全排列
//https://leetcode-cn.com/problems/letter-case-permutation/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void dfs( string &s, vector<string> &ans, string &temp, int startIndex){
        //返回条件
        if(temp.size()==s.size()){
            ans.push_back(temp);
            return ;
        }
        //横向遍历
        for(int i=startIndex;i<s.size();i++){
            //判断是否进入递归
            if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')){
                //进入一次
                temp.push_back(s[i]);
                dfs(s,ans,temp,i+1);
                temp.pop_back();
                //切换大小写再进入一次
                s[i]^=(1<<5);
                temp.push_back(s[i]);
                dfs(s,ans,temp,i+1);
            }else{
                temp.push_back(s[i]);
                dfs(s,ans,temp,i+1);
            }
            temp.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string temp;
        dfs(s,ans,temp,0);
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    string s = "3z4";
    vector<string>arr = Solution().letterCasePermutation(s);
    for(auto i:arr){
        cout<<i<<endl;;
    }
    
    return 0;
}
