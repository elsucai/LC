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
	int helper(TreeNode* root, int &maxchain){
		if(!root){
			maxchain = INT_MIN;
			return INT_MIN;
		}
		int maxsum;
		int lsum, rsum, ltree_chain, rtree_chain;
		lsum = helper(root->left, ltree_chain);
		rsum = helper(root->right, rtree_chain);

		// find max chain rooted at root
		maxchain = root->val + max(0, max(ltree_chain, rtree_chain));
		if(ltree_chain == INT_MIN || rtree_chain == INT_MIN)
			maxsum = max(lsum, max(rsum, maxchain));
		else
			maxsum = max(lsum, max(rsum, max(maxchain, root->val+ltree_chain+rtree_chain)));
		return maxsum;
	}

    int maxPathSum(TreeNode *root) {
		if(!root)
			return 0;
		int maxchain;
		return helper(root, maxchain);
    }
};
