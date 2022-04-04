//
//  main.cpp
//  20
//  20. 有效的括号
//  Created by zhanghao on 2022/4/2.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mymap={
            {'(',')'},
            {'{','}'},
            {'[',']'}
        };
        stack<char> st;
        
        for(int i = s.size() - 1; i >= 0; --i){
            if(s[i] == ')' || s[i] == '}' || s[i] == ']')
                st.push(s[i]);
            else{
                if(mymap[s[i]] == st.top()){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    string ss = "[";
    bool valid = Solution().isValid(ss);
    cout<<valid<<endl;
    return 0;
}
