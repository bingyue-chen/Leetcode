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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
         vector<vector<int>> ans;
         vector<int> path;
         walk(root, sum, path, ans);
         return ans;
    }
    
    void walk(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& ans){
        if(root == NULL) return;
        path.push_back(root->val);
        if(sum == root->val && root->left == NULL && root->right == NULL){
            ans.push_back(path);
        };
        walk(root->left, sum-root->val, path, ans);
        walk(root->right, sum-root->val, path, ans);
        path.pop_back();
    }
};