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
		int ld, rd;
		bool x;
		ld = rd = 0;
		if(!root){
			depth = 0;
			return true;
		}

		x = helper(root->left, ld);
		if(!x)
			return false;
		x = helper(root->right, rd);
		if(!x)
			return false;
		if(abs(ld - rd) > 1)
			return false;
		depth = max(ld, rd) + 1;
		return true;
	}

    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		
		if(!root)
			return true;
		int depth = 0;
		return helper(root, depth);
    }
};
