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
	void helper(vector<int> &ret, TreeNode *root){
		if(!root)
			return;
		helper(ret, root->left);
		ret.push_back(root->val);
		helper(ret, root->right);
	}
	
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
     	vector<int> ret;
     		   
     	helper(ret, root);
     	return ret;
    }
};
