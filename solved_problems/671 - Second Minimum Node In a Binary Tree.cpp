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
    int findSecondMinimumValue(TreeNode* root) {
        
        if(root->left == NULL) return -1;
        
        int left = root->left->val;
        int right = root->right->val;
        
        if(left == right) return -1;
        
        if(left > right){
            if(right == root->val){
                return findMinimumValueWithBound(root->right, right, left);
            }
            return right;
        }
        
        if(right > left){
            if(left == root->val){
                return findMinimumValueWithBound(root->left, left, right);
            }
            return left;
        }
    }
    
    int findMinimumValueWithBound(TreeNode* node, int& lower_bound, int& upper_bound){
        
        if(node->val >= upper_bound){
            return upper_bound;
        }
        
        if(node->left == NULL){
            return (node->val == lower_bound) ? upper_bound : node->val;
        }
        
        int current = (node->val > lower_bound) ? node->val : upper_bound;
        int left    = findMinimumValueWithBound(node->left, lower_bound, upper_bound);
        int right   = findMinimumValueWithBound(node->right, lower_bound, upper_bound);
        
        return min(current, min(left, right));
    }
};