//
//  main.cpp
//  2024
//
//  Created by zhanghao on 2022/3/29.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxConsecutiveChar(string& answerKey, int k, char ch) {
        int n = answerKey.length();
        int ans = 0;
        for (int left = 0, right = 0, sum = 0; right < n; right++) {
            sum += answerKey[right] != ch;
            while (sum > k) {
                sum -= answerKey[left++] != ch;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutiveChar(answerKey, k, 'T'),
                   maxConsecutiveChar(answerKey, k, 'F'));
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    string arr = "TFFT";
    int ans = Solution().maxConsecutiveAnswers(arr, 1);
    cout<< ans <<endl;
    return 0;
}
