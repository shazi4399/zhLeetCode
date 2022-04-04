//
//  main.cpp
//  728
//
//  Created by zhanghao on 2022/3/31.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++ ){
            int temp = i;
            bool flag = true;
            while(temp > 0){
                if(i % (temp%10) == 0)
                    temp = temp/10;
                else{
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                ans.push_back(i);
        }
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> ans = Solution().selfDividingNumbers(1, 22);
    for(auto & i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
