//
// Created by zhanghao on 22-9-19.
//


//acw835 Trie字符串统计
#include <iostream>
using namespace std;

const int N = 100010;

int son[N][26],cnt[N],idx;//下标是0的点，即是根节点也是空节点
char str[N];


void insert(char str[]){
    int p = 0;
    for(int i = 0 ; str[i] ; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++ idx;//如果p这个节点不存在u这个儿子，我就把他创建出来
        p = son[p][u];//走向下一个节点（root->leftchild）
    }
    cnt[p] ++ ; //以这个点结尾的单词串多了一个。
}
int query(char str[]){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;//如果不存在这个单词，直接return 0 就行；
        p = son[p][u];//否则就 走过去；
    }
    return cnt[p];
}

int main(){
    int n ;
    scanf("%d",&n);
    while(n--) {
        char op[2];
        scanf("%s%s", op, str);
        if (op[0] == 'I')insert(str);
        else printf("%d\n", query(str));
    }
}