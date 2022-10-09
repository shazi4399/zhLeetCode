//
// Created by zhanghao on 22-10-9.
// 314 周赛

#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int dx[2] = {0,1},dy[2] = {1,0};
public:
    void dfs(int x,int y,vector<vector<int>>& grid, int k,vector<vector<bool>> & g, int & ans,int m,int n,int & pathsum){
        if(x == m-1 && y == n-1){
            if(pathsum % k == 0){
                ans++;
                ans  = ans % 1000000007;
                return;
            }else
                return;
        }
        //int m = grid.size(); int n = grid[0].size();

        for(int i = 0 ; i < 2; i++){
            int nextx = x + dx[i],nexty = y + dy[i];
            if(nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && g[nextx][nexty] == false){
                pathsum += grid[nextx][nexty];
                g[nextx][nexty] = true;
                dfs(nextx,nexty,grid,k,g,ans,m,n,pathsum);
                pathsum -= grid[nextx][nexty];
                g[nextx][nexty] = false;
            }
        }
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int pathsum = grid[0][0] ;
        vector<vector<bool>> g(m,vector<bool>(n,false));
        dfs(0,0,grid,k,g,ans,m,n,pathsum);
        return ans;

    }
};

int main(){
    vector<vector<int>> grid = {{5,2,4},{3,0,5},{0,7,2}};
    int k = 3;
    int ans = Solution().numberOfPaths(grid,k);
    cout << ans<< endl;
    return 0;
}