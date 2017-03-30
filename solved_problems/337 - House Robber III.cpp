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
    int rob(TreeNode* root) {
        return rob(root, false);
    }
    
    int rob(TreeNode* root, bool isrob){
        if(root == NULL) return 0;
        
        if(isrob){
            return rob(root->left, !isrob) + rob(root->right, !isrob);    
        }
        else{
            int unrobbed = rob(root->left, isrob)+ rob(root->right, isrob);
            int robbed   = root->val + rob(root->left, !isrob) + rob(root->right, !isrob);
            return max(unrobbed, robbed);
        }
    }
};