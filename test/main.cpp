#include <iostream>
#include <vector>


using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
          Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

        void dfs(Node * root,vector<int> & ans){
            if(root == nullptr) return;
            ans.push_back(root->data);
            if(root->left != nullptr)
                dfs(root->left,ans);
            if(root->right != nullptr)
                dfs(root->right,ans);
        }

        void preOrder(Node *root) {
            vector<int> ans;
            dfs(root,ans);
            for(auto & i:ans){
                cout<<i<<" ";
            }
        }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.preOrder(root);
    return 0;
}

