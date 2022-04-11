//
//  main.cpp
//  6037
//
//  Created by zhanghao on 2022/4/10.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

class Solution{
public:
    int largestInteger(int num){
        vector<int> odd,even;
        bool isEven = true;
        int temp = num;
        int ans = 0;
        vector<bool> flag;
        while(temp > 0){

            int digit = temp % 10;
            if(digit % 2 == 1){
                flag.push_back(1);
                odd.push_back(digit);
            }else{
                flag.push_back(0);
                even.push_back(digit);
            }
            temp = temp / 10;
        }
        sort(odd.begin(), odd.end(),greater<int>());
        sort(even.begin(),even.end(),greater<int>());
        reverse(flag.begin(), flag.end());
        for(int i = 0,j = 0,k = 0 ; i < flag.size();i++){
            if(flag[i] == 1){
                ans = ans*10 + odd[j];
                j++;
            }else{
                ans = ans*10 + even[k];
                k++;
            }
        }
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a = Solution().largestInteger(65875);
    cout<<a<<endl;
    return 0;
}
