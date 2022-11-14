//
// Created by zhanghao on 22-11-14.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int> st;
vector<int> nums;

void dfs1(int u, int n, int sum) {
    if(u == n) st.insert(sum);
    else {
        dfs1(u+1, n, sum);
        dfs1(u+1, n, sum + nums[u]);
    }
}

int main() {
    vector<int> arr = {1,2,3};
    nums = arr;
    dfs1(0,3,0);
    for(auto x:st) cout<<x<<" ";
    return 0;
}