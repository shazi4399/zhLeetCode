//
//  main.cpp
//  22. Generate Parentheses
//
//  Created by zhanghao on 2022/4/4.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    void dfs(vector<string>& ans, string path,int left,int right ,int n){
        if(left > n || right > left) return;
        if(path.size() == 4){
            ans.push_back(path);
            return;
        }
        dfs(ans,path+"(",left+1,right,n);
        dfs(ans,path+")",left, right+1,n);
    }
    vector<string> generateParenthesis(int n){
        vector<string> ans;
        dfs(ans,"",0,0,n);
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<string> arr = Solution().generateParenthesis(2);
    for(auto i: arr){
        cout<<i<<",";
    }
    cout<<endl;
    return 0;
}
