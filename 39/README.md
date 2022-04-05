#  39. 组合总和

### 解题思路
![image.png](https://pic.leetcode-cn.com/1649129754-xcZFfQ-image.png)

一开始是想从空路径开始，不断添加节点，直到路径上的和`pathSum` 满足 `pathSum > target` or `pathSum = target`停止。

但是自己画了个地归树的图（如下），发现有重复的组合元素处理不了（红圈和蓝圈重复了），看了下前面的高赞答案都是不断的从 `target`减去节点值。差一点我也随大流，去按照他们的想法走了。。。。
![image.png](https://pic.leetcode-cn.com/1649129541-UtcbdL-image.png)

在下面翻到了Carl大佬的[题解](https://leetcode-cn.com/problems/combination-sum/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-hui-s-7tum/)，发现自己的想法也能做，需要对开始遍历的位置做处理。
![image.png](https://pic.leetcode-cn.com/1649129668-SYGUJp-image.png)


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    void backTrack(vector<int> &path,int & pathSum,vector<int>& candidates,int & target,int startIndex){
        if(pathSum == target){
            ans.push_back(path);
            return;
        }
        if(pathSum > target ){
            return;
        }
        for(int i = startIndex ; i < candidates.size();++i){
            //判断能不能选取此元素
            //选择此元素
            pathSum += candidates[i];
            path.push_back(candidates[i]);
            //进入下一层决策点
            backTrack(path,pathSum,candidates,target,i);//不用i + 1,表示可以重复读取当前的元素。
            //撤销选择的元素
            pathSum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        int pathSum = 0;
        //vector<bool> visited(candidates.size(),false);//不需要这个标记数组了。
        backTrack(path,pathSum,candidates,target,0);
        return ans;
    }
};
```
