//
//  main.cpp
//  124
//
//  Created by zhanghao on 2022/3/25.
//

#include <iostream>
#include <vector>
using namespace std;


 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class BinaryTree{ //二叉树的类
public:
    //根据完全前序遍历创建二叉树
        void createBinaryTree(TreeNode* &root)
        {
            root=new TreeNode();
            int newData;
            cin>>newData;
            if(newData==0)
            {
                root=nullptr;
            }
            else
            {
                root->val=newData;
                createBinaryTree(root->left);
                createBinaryTree(root->right);
            }
        }
    
};

class Solution {

private:
    int maxPathSum(TreeNode* root, int &val) {
        
        if (root == nullptr) return 0;
        int left  = std::max(maxPathSum(root->left,  val), 0);
        int right = std::max(maxPathSum(root->right, val), 0);

        int lmr = root->val + left + right;
        val = std::max(val, lmr);

        return root->val + std::max(left, right);// 沿着更大的一个分支返回
    }

public:
    int maxPathSum(TreeNode* root) {

        int val = INT_MIN;
        maxPathSum(root, val);
        return val;
    }
    

};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";

    BinaryTree tree;
    Solution sol;
    TreeNode* TreeRoot;
    
    tree.createBinaryTree(TreeRoot);
    cout<<"Success"<<endl;
    
    int ans = sol.maxPathSum(TreeRoot);
    cout<<ans<<endl;;
    return 0;
}
