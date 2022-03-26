//
//  main.cpp
//  682
//
//  Created by zhanghao on 2022/3/26.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ret = 0;
        vector<int> points;
        for (auto &op : ops) {
            int n = points.size();
            switch (op[0]) {
                case '+':
                    ret += points[n - 1] + points[n - 2];
                    points.push_back(points[n - 1] + points[n - 2]);
                    break;
                case 'D':
                    ret += 2 * points[n - 1];
                    points.push_back(2 * points[n - 1]);
                    break;
                case 'C':
                    ret -= points[n - 1];
                    points.pop_back();
                    break;
                default:
                    ret += stoi(op);
                    points.push_back(stoi(op));
                    break;
            }
        }
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<string> s = {"5","2","C","D","+"};
    int ans = 0;
    Solution sol;
    ans = sol.calPoints(s);
    cout<<ans<<endl;
    
    return 0;
}
