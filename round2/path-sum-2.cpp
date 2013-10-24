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
	void helper(TreeNode* root, vector<vector<int> > &ret, vector<int> &cur, int sum){
		cur.push_back(root->val);
		if(!root->left && !root->right){
			if(root->val == sum){
				ret.push_back(cur);
			}
			cur.erase(cur.end()-1);
			return;
		}
		if(root->left)
			helper(root->left, ret, cur, sum-root->val);
		if(root->right)
			helper(root->right, ret, cur, sum-root->val);
		
		cur.erase(cur.end()-1);
		return;
	}
	
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		vector<vector<int> > ret;
		if(!root)
			return ret;
		
		vector<int> cur;
		helper(root, ret, cur, sum);
		return ret;
    }
};