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
   bool isBalanced(TreeNode* root) {
        return (getDepthAndBalancedCheck(root) == -1) ? false : true;
    }
    
    /*
    -1 not Balanced otherwise depth
    */
    int getDepthAndBalancedCheck(TreeNode* current){
        
        if(current == NULL) return 0;
        
        int ldepth= getDepthAndBalancedCheck(current->left);
        if(ldepth == -1) return -1;
        
        int rdepth = getDepthAndBalancedCheck(current->right);
        if(rdepth == -1) return -1;
        
        if(abs(ldepth - rdepth) > 1) return -1;
        
        return max(ldepth, rdepth) + 1;
    }
};