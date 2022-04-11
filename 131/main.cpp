//
//  main.cpp
//  131
//
//  Created by zhanghao on 2022/4/7.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<string>> partition(string s){
        vector<vector<string>> result;
        vector<string> path;
        dfs(s,path,result,0,1);
        return result;
    }
    
    void dfs(string &s,vector<string>& path,vector<vector<string>> & result,size_t prev,size_t start){
        if(start == s.size()){
            if(isPalindrome(s, prev, start - 1)){
                path.push_back(s.substr(prev,start-prev));
                result.push_back(path);
                path.pop_back();
            }
            return;
        }
        dfs(s,path,result,prev,start + 1);
        if(isPalindrome(s, prev, start - 1)){
            path.push_back(s.substr(prev,start - prev));
            dfs(s,path,result,start,start + 1);
            path.pop_back();
        }
    }
    
    bool isPalindrome(const string & s,int start,int end){
        //while(start < end && )
        while(start < end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string s = "aab";
    vector<vector<string>> ans = Solution().partition(s);
    for(auto i : ans){
        for(auto j : i){
            cout<< j << " ";
        }
        cout<<endl;
    }
    return 0;
}

