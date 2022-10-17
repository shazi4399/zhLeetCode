//
// Created by zhanghao on 22-10-12.
//


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1010;

int n,m;
int v[N],w[N];
//int f[N];

int main(){

    cin >> n >> m;
    //vector<vector<int>> f(n+1,vector<int>(m+1,0));
    vector<int> f(m+1,0);

    for(int i = 1; i <= n ; i++) cin >> v[i] >> w[i];

    for(int i = 1; i <= n ; i++)
        for(int j = m ; j >= v[i]; j--)
            f[j] = max(f[j],f[j - v[i]] + w[i]);
    cout << f[m] <<endl;
    return 0;
}