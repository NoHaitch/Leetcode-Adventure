#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Recursion
    vector<int> recInorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        if(root->left == nullptr && root->right == nullptr){
            return {root->val};
        }

        vector<int> res;
        if(root->right == nullptr){
            res = inorderTraversal(root->left);
            res.push_back(root->val);
        } else if(root->left == nullptr){
            res = inorderTraversal(root->right);
            res.insert(res.begin(), root->val);
        } else{
            res = inorderTraversal(root->left);
            res.push_back(root->val);

            vector<int> rightNode = inorderTraversal(root->right);
            res.insert( res.end(), rightNode.begin(), rightNode.end());
        }
        
        return res;
    }

    // no Recursion
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> result;

       TreeNode* curr = root;
        
        while(curr != nullptr) {
            if(curr->left == nullptr) {
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* leftChild = curr->left;

                while(leftChild->right != nullptr) {
                    leftChild = leftChild->right;
                }

                leftChild->right = curr;

                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }       
        }
        return result;
    }
};