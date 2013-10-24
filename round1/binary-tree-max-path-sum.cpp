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
	int helper(int &global_max, TreeNode* root){
		if(!root)
			return 0;
		//the path sum begin with root
		// could be root itself
		int self = root->val;
		// could be in its left sub tree single path
		int left_max = helper(global_max, root->left);
		// could be in its right sub tree
		int right_max = helper(global_max, root->right);
		
		int ret = max(self, max(left_max+self, right_max+self));
		global_max = max(global_max, max(left_max+right_max+self, ret));
		return ret;
	}
	
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int global_max = INT_MIN;
		
		if(!root)
			return 0;
		
		int tmp = helper(global_max, root);
		return global_max;
    }
};