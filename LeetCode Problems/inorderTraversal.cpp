//Given the root of a binary tree, return the inorder traversal of its nodes' values.

#include <iostream>
#include <vector>

//Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    void inOrder(TreeNode* root, std::vector<int>& result) 
    {
        if(!root)
        {
            return;
        }

        inOrder(root->left, result);

        result.emplace_back(root->val);

        inOrder(root->right, result);
    }

    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        std::vector<int> result;

        inOrder(root, result);
        
        return result;
    }
};