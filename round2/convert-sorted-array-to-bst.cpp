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
		TreeNode* left = helper(num, s, m-1);
		TreeNode* right = helper(num, m+1, e);
		TreeNode* root = new TreeNode(num[m]);
		root->left = left;
		root->right = right;
		return root;
	}
	
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		if(num.empty())
			return NULL;
		int s, e, m;
		s = 0;
		e = num.size()-1;
		return helper(num, s, e);
    }
};