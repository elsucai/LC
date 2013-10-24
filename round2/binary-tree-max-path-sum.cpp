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
	void helper(TreeNode* root, int &maxsum, int &lsum, int &rsum){
		lsum = rsum = 0;
		
		if(!root){
			return;
		}
		int local_lsum, local_rsum;
		local_lsum = local_rsum = 0;

		if(root->left){
			helper(root->left, maxsum, local_lsum, local_rsum);
			lsum = max(local_lsum, local_rsum) + root->left->val;
			lsum = max(lsum, root->left->val);
		}
		if(root->right){
			helper(root->right, maxsum, local_lsum, local_rsum);
			rsum = max(local_lsum, local_rsum) + root->right->val;
			rsum = max(rsum, root->right->val);
		}

		maxsum = max(maxsum, lsum+root->val);
		maxsum = max(maxsum, rsum+root->val);
		maxsum = max(maxsum, root->val);
		maxsum = max(maxsum, lsum+rsum+root->val);
	}

    int maxPathSum(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

		if(!root)
			return 0;
		int maxsum = INT_MIN;
		int lsum, rsum;
		lsum = rsum = 0;
		helper(root, maxsum, lsum, rsum);

		return maxsum;
    }
};
