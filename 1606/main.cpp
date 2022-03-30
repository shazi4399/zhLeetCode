//
//  main.cpp
//  1606
//
//  Created by zhanghao on 2022/3/30.
//  1606. 找到处理最多请求的服务器[困难]

#include <algorithm>　　 //STL 通用算法

#include <cmath>           //定义数学函数

#include <deque>　　　　　 //STL 双端队列容器
#include <exception>　　　 //异常处理类
#include <fstream>         //文件输入／输出
#include <functional>　　　//STL 定义运算函数（代替运算符）
#include <limits>          //定义各种数据类型最值常量
#include <list>　　　　　　//STL 线性列表容器
#include <map>　　　　　　 //STL 映射容器

#include <iostream>        //数据流输入／输出
#include <queue>　　　　　 //STL 队列容器
#include <set>　　　　　　 //STL 集合容器
#include <sstream>　　　　 //基于字符串的流
#include <stack>　　　　　 //STL 堆栈容器
#include <stdexcept>　　　 //标准异常类
#include <streambuf>　　　 //底层输入／输出支持
#include <string>　　　　　//字符串类
#include <utility>　　　　 //STL 通用模板类
#include <vector>　　　　　//STL 动态数组容器
#include <cwchar>          //宽字符处理及输入／输出
#include <cwctype>         //宽字符分类

using namespace std;

class Solution {
    struct node{
        int finish;
        int id;

        bool operator >(const node& other)const{
            if(finish == other.finish) return id > other.id;
            return finish >other.finish;
        }
    };
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k);
        priority_queue<node,vector<node>,greater<>> working;
        set<int> waiting;
        vector<int> ans;
        int m = 0;
        for(int i = 0; i < k;i++)
            waiting.insert(i);
        for(int i = 0 ; i < arrival.size();i++){
            while(working.size() && working.top().finish <= arrival[i]){
                waiting.insert(working.top().id);
                working.pop();
            }
            auto cur = waiting.lower_bound(i % k);
            if(cur == waiting.end())
                cur = waiting.begin();
            if(cur == waiting.end())
                continue;
            working.push({arrival[i] + load[i],*cur});
            m = max(m, ++cnt[*cur]);
            waiting.erase(cur);
        }
        for(int i = 0 ; i < k; i++){
            if(cnt[i] == m)
                ans.push_back(i);
        }
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    vector<int>arrival = {1,2,3};
    vector<int>load = {10,12,11};
    vector<int> ans = Solution().busiestServers(3, arrival, load);
    for(auto & i:ans){
        cout<<i<<endl;
    }

    return 0;
}
