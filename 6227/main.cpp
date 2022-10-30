//
// Created by zhanghao on 22-10-30.
//
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
class Solution {
public:
    struct cmp{
        bool operator()(PII & p1,PII & p2){
            return p1.first > p2.first;
        }
    };

    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        stack<PII> stk;
        priority_queue<PII,vector<PII>,cmp> que;
        stk.push({100000007,-1});
        que.push({100000007,-1});
        vector<int> ans (n,-1);
        for(int i = 0; i < n; i++){
            while(nums[i] > que.top().first){
                auto [a,t] = que.top();
                que.pop();
                ans[t] = nums[i];
            }
            while(nums[i] > stk.top().first) {
                PII p = stk.top();
                stk.pop();
                que.push(p);
            }
            stk.push({nums[i], i});
        }
        return ans;
    }
};

int main(){
    vector<int> arr = {2,4,0,9,6};
    vector<int> ans = Solution().secondGreaterElement(arr);
    for(auto i : ans)
        cout << i << " ";
    return 0;
}