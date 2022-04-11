//
//  main.cpp
//  2224
//
//  Created by zhanghao on 2022/4/8.
//
/**
 给你两个字符串 current 和 correct ，表示两个 24 小时制时间 。

 24 小时制时间 按 "HH:MM" 进行格式化，其中 HH 在 00 和 23 之间，而 MM 在 00 和 59 之间。最早的 24 小时制时间为 00:00 ，最晚的是 23:59 。

 在一步操作中，你可以将 current 这个时间增加 1、5、15 或 60 分钟。你可以执行这一操作 任意 次数。

 返回将 current 转化为 correct 需要的 最少操作数 。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/minimum-number-of-operations-to-convert-time
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 输入：current = "02:30", correct = "04:35"
 输出：3
 解释：
 可以按下述 3 步操作将 current 转换为 correct ：
 - 为 current 加 60 分钟，current 变为 "03:30" 。
 - 为 current 加 60 分钟，current 变为 "04:30" 。
 - 为 current 加 5 分钟，current 变为 "04:35" 。
 可以证明，无法用少于 3 步操作将 current 转化为 correct 。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/minimum-number-of-operations-to-convert-time
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        int corHH = stoi(correct.substr(0,2));
        int curHH = stoi(current.substr(0,2));
        int HH = (corHH - curHH + 24)%24;
        
        int corMM = stoi(correct.substr(3,5));
        int curMM = stoi(current.substr(3,5));
        int MM = (corMM - curMM + 60)%60;
        
        int ans = 0;
        
        ans = HH + (MM / 15) + (MM%15)/5 + ((MM%15)%5);
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int ans = Solution().convertTime("02:30", "04:35");
    cout<<ans<<endl;
    return 0;
}
