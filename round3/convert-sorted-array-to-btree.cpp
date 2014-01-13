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
	TreeNode* helper(vector<int> &num, int s, int e){
		if(s > e)
			return NULL;
		int m = s+(e-s)/2;
		TreeNode* root = new TreeNode(num[m]);
		root->left = helper(num, s, m-1);
		root->right = helper(num, m+1, e);
		return root;
	}

    TreeNode *sortedArrayToBST(vector<int> &num) {
		return helper(num, 0, num.size()-1);
    }
};
