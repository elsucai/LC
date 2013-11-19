/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isMirror(TreeNode* p, TreeNode* q){
        if(!p && !q)
            return true;
        if(p && !q || q && !p || p->val != q->val)
            return false;
        return(isMirror(p->left, q->right) && isMirror(p->right, q->left));
    }

    bool isSymmetric(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!root)
            return true;
        return isMirror(root->left, root->right);
    }
};