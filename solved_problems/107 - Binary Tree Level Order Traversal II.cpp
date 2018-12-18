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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> lou;
        
        if(root != NULL){
            buildLevelOrderUp(root, lou, 0);
        }
        
        reverse(lou.begin(), lou.end());
        
        return lou;
    }
    
    void buildLevelOrderUp(TreeNode* root,vector<vector<int>>& lou, int depth) {
        if (lou.size() <= depth) lou.push_back({});
        lou[depth].push_back(root->val);
        
        if(root->left != NULL) buildLevelOrderUp(root->left, lou, depth + 1);
        if(root->right != NULL) buildLevelOrderUp(root->right, lou, depth + 1);
    }
};