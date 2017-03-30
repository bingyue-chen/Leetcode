/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        struct TreeNode *original_left, *original_right;
        
        if(root != NULL){
            original_left = root->left;
            original_right = root->right;
            root->left = this->invertTree(original_right);
            root->right = this->invertTree(original_left);
        }
        
        return root;
    }
};