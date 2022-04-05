# 一 思路

这道题目和[39.组合总和](https://leetcode-cn.com/problems/combination-sum/)如下区别：

- 1 本题candidates 中的每个数字在每个组合中只能使用一次。
- 2 本题数组candidates的元素是有重复的，而39.组合总和是无重复元素的数组candidates

 最后本题和39.组合总和要求一样，解集不能包含重复的组合。

**本题的难点在于区别2中：集合（数组candidates）有重复元素，但还不能有重复的组合。**

一些同学可能想了：我把所有组合求出来，再用set或者map去重，这么做很容易超时！

所以要在搜索的过程中就去掉重复组合。

很多同学在去重的问题上想不明白，其实很多题解也没有讲清楚，反正代码是能过的，感觉是那么回事，稀里糊涂的先把题目过了。



这个去重为什么很难理解呢，**所谓去重，其实就是使用过的元素不能重复选取。** 这么一说好像很简单！

都知道组合问题可以抽象为树形结构，那么“使用过”在这个树形结构上是有两个维度的，一个维度是同一**树枝**上使用过，一个维度是同一**树层**上使用过。没有理解这两个层面上的“使用过” 是造成大家没有彻底理解去重的根本原因。



那么问题来了，我们是要同一树层上使用过，还是同一树枝上使用过呢？

回看一下题目，元素在同一个组合内是可以重复的，怎么重复都没事，但两个组合不能相同。

所以我们要去重的是同一树层上的“使用过”，同一树枝上的都是一个组合里的元素，不用去重。

为了理解去重我们来举一个例子，candidates = [1, 1, 2], target = 3，（方便起见candidates已经排序了）

**强调一下，树层去重的话，需要对数组排序！**

选择过程树形结构如图所示：

![40.组合总和II](https://pic.leetcode-cn.com/1631605642-VAfqxG-file_1631605642774)

可以看到图中，每个节点相对于 39.组合总和我多加了used数组，这个used数组下面会重点介绍。

## 回溯三部曲

- 递归函数参数

与39.组合总和套路相同，但是还要加一个bool型数组used，**用来记录同一树枝上的元素是否使用过。**

这个集合去重的重任就是used来完成的。

代码如下：

```C++
vector<vector<int>> result; // 存放组合集合
vector<int> path;           // 符合条件的组合
void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
```



- 递归终止条件

与39.组合总和相同，终止条件为` sum > target `和` sum == target`。

代码如下：

```C++
if (sum > target) { // 这个条件其实可以省略
    return;
}
if (sum == target) {
    result.push_back(path);
    return;
}
```


`sum > target `这个条件其实可以省略，因为和在递归单层遍历的时候，会有剪枝的操作，下面会介绍到。

- 单层搜索的逻辑

这里与39.组合总和最大的不同就是要去重了。

前面我们提到：要去重的是“同一树层上的使用过”，如果判断同一树层上元素（相同的元素）是否使用过了呢。

**如果candidates[i] == candidates[i - 1] 并且 used[i - 1] == false，就说明：前一个树枝，使用了candidates[i - 1]，也就是说同一树层使用过candidates[i - 1]。**

此时for循环里就应该做continue的操作。

这块比较抽象，如图：

![40.组合总和II1](https://pic.leetcode-cn.com/1631605642-NCQSGN-file_1631605642859)

我在图中将used的变化用橘黄色标注上，可以看出在candidates[i] == candidates[i - 1]相同的情况下：

- used[i - 1] == true，说明同一树支candidates[i - 1]使用过
- used[i - 1] == false，说明同一树层candidates[i - 1]使用过

**这块去重的逻辑很抽象，网上搜的题解基本没有能讲清楚的，如果大家之前思考过这个问题或者刷过这道题目，看到这里一定会感觉通透了很多！**

那么单层搜索的逻辑代码如下：

```C++
for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
    // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
    // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
    // 要对同一树层使用过的元素进行跳过
    if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
        continue;
    }
    sum += candidates[i];
    path.push_back(candidates[i]);
    used[i] = true;
    backtracking(candidates, target, sum, i + 1, used); // 和39.组合总和的区别1：这里是i+1，每个数字在每个组合中只能使用一次
    used[i] = false;
    sum -= candidates[i];
    path.pop_back();
}
```


注意`sum + candidates[i] <= target`为剪枝操作，在39.组合总和有讲解过！

# 二 C++代码

回溯三部曲分析完了，整体C++代码如下：

```C++
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        path.clear();
        result.clear();
        // 首先把给candidates排序，让其相同的元素都挨在一起。
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};
```



补充
这里直接用startIndex来去重也是可以的， 就不用used数组了。

```C++
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // 要对同一树层使用过的元素进行跳过
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        // 首先把给candidates排序，让其相同的元素都挨在一起。
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
```





# 三 总结

本题同样是求组合总和，但就是因为其数组candidates有重复元素，而要求不能有重复的组合，所以相对于39.组合总和难度提升了不少。

关键是去重的逻辑，代码很简单，网上一搜一大把，但几乎没有能把这块代码含义讲明白的，基本都是给出代码，然后说这就是去重了，究竟怎么个去重法也是模棱两可。

所以Carl有必要把去重的这块彻彻底底的给大家讲清楚，就连“树层去重”和“树枝去重”都是我自创的词汇，希望对大家理解有帮助！


回溯算法力扣题目总结
按照如下顺序刷力扣上的题目，相信会帮你在学习回溯算法的路上少走很多弯路。

- 关于回溯算法，你该了解这些！

<img src="https://img-blog.csdnimg.cn/20210219192050666.png" alt="回溯算法大纲" style="zoom: 50%;" />

- 组合问题
  [77.组合](https://leetcode-cn.com/problems/combinations/)
  [216.组合总和III](https://leetcode-cn.com/problems/combination-sum-iii/)
  [17.电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number)
  [39.组合总和](https://leetcode-cn.com/problems/combination-sum)
  [40.组合总和II](https://leetcode-cn.com/problems/combination-sum-ii)
- 分割问题
  [131.分割回文串](https://leetcode-cn.com/problems/palindrome-partitioning)
  [93.复原IP地址]()
- 子集问题
  [78.子集](https://leetcode-cn.com/problems/subsets)
  [90.子集II](https://leetcode-cn.com/problems/subsets-ii)
- 排列问题
  [46.全排列](https://leetcode-cn.com/problems/permutations)
  [47.全排列II](https://leetcode-cn.com/problems/permutations-ii)
- 棋盘问题
  [51.N皇后](https://leetcode-cn.com/problems/n-queens)
  [37.解数独](https://leetcode-cn.com/problems/sudoku-solver)
- 其他
  [491.递增子序列](https://leetcode-cn.com/problems/increasing-subsequences)
  [332.重新安排行程](https://leetcode-cn.com/problems/reconstruct-itinerary)
  [回溯算法总结篇](https://programmercarl.com/%E5%9B%9E%E6%BA%AF%E6%80%BB%E7%BB%93.html#%E6%8E%92%E5%88%97%E9%97%AE%E9%A2%98-%E4%BA%8C)


大家好，我是程序员Carl，点击我的头像，查看力扣详细刷题攻略，你会发现相见恨晚！

如果感觉题解对你有帮助，不要吝啬给一个👍吧！

作者：carlsun-2
链接：https://leetcode-cn.com/problems/combination-sum-ii/solution/dai-ma-sui-xiang-lu-dai-ni-xue-tou-hui-s-ig29/
来源：力扣（LeetCode）
<!--著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。-->
