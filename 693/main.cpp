//
//  main.cpp
//  693
//
//  Created by zhanghao on 2022/3/28.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flagOrder = false;
        if(n%2 == 1){ //n是奇数
            while(n && n!=1){
                if((n&1) == 1 && (n&2)==0){
                    n = n>>2;
                    continue;
                }else{
                    return false;
                }
            }
            return true;
        } else{     //n是哦数
            while(n && n!=2){
                if((n&1) == 0 && (n&2) ==2){
                    n = n>>2;
                    continue;
                }else{
                    return false;
                }
            }
            return true;
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    bool flag = Solution().hasAlternatingBits(1);
    cout<<flag<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
