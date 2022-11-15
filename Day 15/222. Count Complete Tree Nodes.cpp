// https://leetcode.com/problems/count-complete-tree-nodes/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int fun(TreeNode* root){
        
        if(root==NULL) return 1;
        
        int left = fun(root->left);
        int right = fun(root->right);
        
        return left+right;
        
        
    }
    
    int countNodes(TreeNode* root) {
       return fun(root)-1;
    }
};