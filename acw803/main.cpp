//
// Created by zhanghao on 22-9-18.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> PII;
const int N = 100010;

int n ;
vector<PII> segs;

void merge(vector<PII> &segs){
    vector<PII> res;
    sort(segs.begin(),segs.end());//pair排序会有限以左端点排序，然后在右端点排序；
    int st = -2e9,ed = -2e9;
    for(auto seg : segs){
        if(ed < seg.first){
            if(st != -2e9) res.push_back({st,ed});
            st = seg.first,ed = seg.second;
        }
        else ed = max(ed,seg.second);
    }
    if( st != -2e9) res.push_back({st,ed});//防止segs是空的
    segs = res;
}

int main(){
    cin >> n;
    for(int i = 0 ; i < n; i++){
        int l ,r;
        cin >> l >> r;
        segs.push_back({l,r});
    }
    merge(segs);
    cout<< segs.size()<<endl;

    return 0;
}