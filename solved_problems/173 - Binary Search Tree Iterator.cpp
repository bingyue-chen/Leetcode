/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    
    stack<TreeNode*> s;
    
    BSTIterator(TreeNode *root) {
        this->pushLeftNode(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* sn = s.top();
        s.pop();
        if(sn->right != NULL)
            pushLeftNode(sn->right);
        return sn->val;
    }
    
    void pushLeftNode(TreeNode *curr){
        while(curr != NULL){
            this->s.push(curr);
            curr = curr->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */