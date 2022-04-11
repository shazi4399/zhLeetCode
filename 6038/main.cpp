//
//  main.cpp
//  6038
//
//  Created by zhanghao on 2022/4/10.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string minimizeResult(string expression) {
        int n = expression.find('+');
        cout<<n<<endl;
        
        for(int i = 0 ; i < n;++i){
            string a = expression.substr(0,i);
            string b = expression.substr(i, m - i);
            int numA = (a.size() == 0 ? 1 : stoi(a));
            int numB = stoi(b);
            
            
        }
        return "";
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution().minimizeResult("12+34");
    return 0;
}
