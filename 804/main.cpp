//
//  main.cpp
//  804
//
//  Created by zhanghao on 2022/4/10.
//
//804. 唯一摩尔斯密码词
//https://leetcode-cn.com/problems/unique-morse-code-words/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution{
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> arr = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        unordered_set<string> myset;
        for(int i = 0 ; i < words.size();++i){
            string path = "";
            for(int j = 0 ; j < words[i].size(); ++j){
                path += arr[words[i][j]-'a'];
            }
            myset.insert(path);
        }
        return myset.size();
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<string> arr = {"gin", "zen", "gig", "msg"};
    int ans = Solution().uniqueMorseRepresentations(arr);
    cout<<ans<<endl;
    return 0;
}
