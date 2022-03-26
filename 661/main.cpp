//
//  main.cpp
//  661
//
//  Created by zhanghao on 2022/3/24.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const int dx[9] = {0,0,0,-1,1,-1,-1,1,1};
        const int dy[9] = {0,1,-1,0,0,-1,1,1,-1};
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i = 0 ;i < n;++i){
            for(int j = 0 ; j < m;++j){
                int temp = 0;
                int count = 0;
                int x= 0,y =0;
                for(int k = 0;k<9;++k){
                    x = i + dx[k];
                    y = j + dy[k];
                    if(x>=0 && x<n && y>=0 && y < m){
                        temp += img[x][y];
                        count++;
                    }else{
                        temp += 0;
                    }
                }
                ans[i][j] = temp/count;
            }
        }
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution sol;
    vector<vector<int>> img = {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};
    vector<vector<int>> res(5,vector<int>(3));
    res = sol.imageSmoother(img);
    for(auto & xi:res){
        for(auto & yj:xi )
            cout<<yj<<" ";
        cout<<endl;
    }
    return 0;
}
