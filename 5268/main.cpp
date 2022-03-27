//
//  main.cpp
//  5268
//
//  Created by zhanghao on 2022/3/27.
//

#include<iostream>
#include<vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> c1;
        unordered_set<int> n1;
        unordered_set<int> n2;
        vector<vector<int>> ans;//(3, vector<int>(2, 0));
        vector<int> temp1;
        vector<int> temp2;
        for(auto & i:nums1){
            n1.emplace(i);
        }
//        for(auto &i: n1){
//            cout<<i<<" ";
//        }
        for(auto & i:nums2){
            n2.emplace(i);
        }
//        for(auto &i: n1){
//            cout<<i<<" ";
//        }
        for(unordered_set<int>::iterator it=n1.begin() ;it!=n1.end();it++)
        {
            if(!n2.count(*it))
                temp1.push_back(*it);
        }

        for(unordered_set<int>::iterator it = n2.begin()
            ;it != n2.end();it++){
            if(!n1.count(*it))
                temp2.push_back(*it);
        }
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    Solution sol;
    vector<int> a ={1,2,3};
    vector<int> b = {2,4,6};
    vector<vector<int>> arr = sol.findDifference(a, b);
    //sol.findDifference(a, b);
    for(auto & i:arr){
        for(auto & j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}

