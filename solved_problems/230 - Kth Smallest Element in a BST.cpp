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
    
    map<int, int> bigger;

    int kthSmallest(TreeNode* root, int k, int leftCount = 0) {
        int left = 0, ans = 0, right = 0;
        
        if(root->left != NULL){
            ans = kthSmallest(root->left, k, leftCount);
            left = bigger[root->left->val];
            bigger[root->val] = left+1;
            if(k <= left) return ans;
        }
        else{
            bigger[root->val] = leftCount+1;
        }
        
        if(bigger[root->val] == k) return root->val;
        
        /*cout << "current " << to_string(root->val) << " after left : " << endl;
        for(map<int, int>::iterator it = bigger.begin(); it != bigger.end(); ++it){
            cout << to_string(it->first) <<  " " << to_string(it->second) << endl;;
        }*/
        
        if(root->right != NULL){
            ans = kthSmallest(root->right, k, bigger[root->val]);
            right = bigger[root->right->val];
            bigger[root->val] = right;
            if(k <= right) return ans;
        }
        
        /*cout << "current " << to_string(root->val) << " after right : " << endl;
        for(map<int, int>::iterator it = bigger.begin(); it != bigger.end(); ++it){
            cout << to_string(it->first) <<  " " << to_string(it->second) << endl;;
        }*/
        
        return root->val;
    }
    
};