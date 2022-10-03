//
// Created by zhanghao on 22-10-3.
// 堆优化版 dijkstra算法
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

const int N = 100010;

typedef pair<int,int> PII;
const int N = 100010;

int h[N],e[N],ne[N],idx;
int w[N];
int dist[N];
bool st[N];

int n,m;
priority_queue<int> p;
void add(int x,int y,int c){
    w[idx] = c;
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}

int dijkstra(){
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    while(heap.size()){
        PII k = heap.top();
        heap.pop();
        int ver = k.second,distance = k.first;

        if(st[ver]) continue;
        st[ver] = true;

        for(int i = h[ver]; i != -1 ; i = ne[i]){
            int j = e[i];
            if(dist[j] > distance + w[i]){
                dist[j] = distance + w[i];
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main(){
    memset(h,-1,sizeof(h));
    cin >> n >> m;
    while(m--){
        int x,y,c;
        cin>>x>>y>>c;
        add(x,y,c);
    }
    cout<< dijkstra() << endl;
    return 0;
}



