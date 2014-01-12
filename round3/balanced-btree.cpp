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
	bool helper(TreeNode* root, int &depth){
		if(!root){
			depth = 0;
			return true;
		}
		int ld, rd;
		if(!helper(root->left, ld) || !helper(root->right, rd))
			return false;
		depth = 1 + max(ld, rd);
		if(abs(ld - rd) > 1)
			return false;
		return true;
	}

    bool isBalanced(TreeNode *root) {
		int depth = 0;
		return helper(root, depth);        
    }
};
