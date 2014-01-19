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
	void helper(vector<vector<int> > &ret, vector<int> &one, TreeNode* root, int sum){
		if(!root)
			return;
		if(!root->left && !root->right){
			if(root->val == sum){
				one.push_back(root->val);
				ret.push_back(one);
				one.pop_back();
			}
			return;
		}
		one.push_back(root->val);
		helper(ret, one, root->left, sum - root->val);
		helper(ret, one, root->right, sum - root->val);
		one.pop_back();
	}

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > ret;
		vector<int> one;

		helper(ret, one, root, sum);
		return ret;
    }
};
