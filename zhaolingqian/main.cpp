//
//  main.cpp
//  zhaolingqian
//
//  Created by zhanghao on 2022/4/9.
//
/**
 问题：给定 n 种不同面值的硬币，分别记为 c[0], c[1], c[2], … c[n]，同时还有一个总金额 k，编写一个函数计算出最少需要几枚硬币凑出这个金额 k？每种硬币的个数不限，且如果没有任何一种硬币组合能组成总金额时，返回 -1。
 
 示例 1：
 输入：c[0]=1, c[1]=2, c[2]=5, k=12
 输出：3
 解释：12 = 5 + 5 + 2
 
 示例 2：
 输入：c[0]=5, k=7
 输出：-1
 解释：只有一种面值为5的硬币，怎么都无法凑出总价值为7的零钱。
 */
#include <iostream>
#include <vector>

void GetMinCountsHelper(int total, const std::vector<int>& values, std::vector<int> currentCounts, std::vector<std::vector<int>>& combinations) {
    if (!total) { // 如果余额为0，说明当前组合成立，将组合加入到待选数组中
        combinations.push_back(currentCounts);
        return;
    }

    int valueLength = values.size();
    for (int i = 0;  i < valueLength; i ++) { // 遍历所有面值
        int currentValue = values[i];
        if (currentValue > total) { // 如果面值大于当前总额，直接跳过
            continue;
        }

        // 否则在当前面值数量组合上的对应位置加1
        std::vector<int> newCounts = currentCounts;
        newCounts[i] ++;
        int rest = total - currentValue;
        
        GetMinCountsHelper(rest, values, newCounts, combinations); // 求解剩余额度所需硬币数量
    }
    return;
}

int GetMinimumHelper(const std::vector<std::vector<int>>& combinations) {
    // 如果没有可用组合，返回-1
    if (!combinations.size()) { return -1; }

    int minCount = INT_MAX;
    for (const std::vector<int>& counts : combinations) {
        int total = 0; // 求当前组合的硬币总数
        for (int count : counts) { total += count; }

        // 保留最小的
        if (total < minCount) { minCount = total; }
    }

    return minCount;
}

int GetMinCountOfCoins() {
    std::vector<int> values = { 5, 3 }; // 硬币面值的数组
    int total = 11; // 总值

    std::vector<int> initialCounts(values.size(), 0); // 初始值(0,0)
    std::vector<std::vector<int>> coinCombinations; // 存储所有组合
    GetMinCountsHelper(total, values, initialCounts, coinCombinations); // 求解所有组合（不去重）

    return GetMinimumHelper(coinCombinations); // 输出答案
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    GetMinCountOfCoins();
    return 0;
}
