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
	bool helper(TreeNode* root, int lb, int rb){
		if(!root)
			return true;
		if(root->val < lb || root->val > rb)
			return false;
		return helper(root->left, lb, root->val-1) && helper(root->right, root->val+1, rb);
	}

    bool isValidBST(TreeNode *root) {
		return helper(root, INT_MIN, INT_MAX);        
    }
};
