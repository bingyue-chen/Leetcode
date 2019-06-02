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
    int sum;
    
    Solution(){
        this->sum = 0;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(root != NULL){
            convertBST(root->right);
            this->sum += root->val;
            root->val = this->sum;
            convertBST(root->left);
        }
        return root;
    }

};
