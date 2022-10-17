////
//// Created by zhanghao on 22-10-15.
////https://www.lanqiao.cn/courses/4469/learning/?id=233734&compatibility=false
//#include <iostream>
//#include <queue>
//#include <cstring>
//#include <vector>
//using namespace std;
//
//const int N = 107;
//
////int g[N][N],d[N][N];
//
//
//typedef pair<int,int> PII;
//int n,m;
//
//int bfs(vector<vector<int>> & g,vector<vector<int>> & d){
//    int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};
//    queue<PII> qu;
//    qu.push({0,0});
//    d[0][0] = 0;
//
//    while(!qu.empty()){
//        auto cur = qu.front();
//        qu.pop();
//        for(int i = 0 ; i < 4 ;i++){
//            int x = cur.first + dx[i], y = cur.second + dy[i];
//            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1){
//                d[x][y] = d[cur.first][cur.second] + 1;
//                qu.push({x,y});
//            }
//        }
//    }
//    return d[n-1][m-1];
//}
//
//int main(){
//    vector<vector<int>> g(N,vector<int>(N,0));
//    vector<vector<int>> d(N,vector<int>(N,-1));
//    cin >> n >> m;
//    for(int i = 0 ; i < n;i++)
//        for(int j = 0 ; j < m ;j++)
//            cin >> g[i][j];
//    cout << bfs(g,d)<<endl;
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 1e2 + 7;
vector<vector<int>> d(N,vector<int>(N,-1));
vector<vector<int>> g(N,vector<int>(N));
//int g[N][N];
int n, m;


int bfs() {
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    queue <PII> q;
    d[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 1 && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second]  + 1;
                q.push({x, y});
            }
        }
    }
    return d[n - 1][m - 1];
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    cout << bfs() << endl;
    return 0;
}