//
// Created by zhanghao on 22-10-2.


//详情参见 https://acwing.com/solution/content/13513

#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010, M = N * 2;

int n,m;
int ans = N;
int h[N],e[M],ne[M],idx; //h[]存放链表的头结点，拉链法。
bool st[N];

void add(int a,int b){
    e[idx] =b;ne[idx] = h[a]; h[a] = idx++; //连接表问题都是这么存的。头插法。
}

/* 树的dfs模板
void dfs(int u){
    st[u] = true;  //标记一下已经被搜索过了
    for(int i = h[u];i != -1 ;i = ne[i]){ //遍历节点所有的子孩子。
        int j = e[i];
        if(!st[j]) dfs(j);
    }
}
*/
int dfs(int u){
    int res = 0;
    st[u] = true;
    int sum = 1;

    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            int s = dfs(j);
            res = max(res,s);
            sum += s;
        }
    }

    res = max(res,n-sum);
    ans = min(res,ans);
    return sum;
}

int main(){
    memset(h,-1,sizeof h)
    cin >> n;
    for(int i = 0 ; i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        add(a,b);add(b,a);
    }
    dfs(1);
    cout<< ans << endl;
    return 0;
}

