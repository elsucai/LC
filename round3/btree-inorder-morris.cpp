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
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int> ret;
		if(!root)
			return ret;
		TreeNode* cur = root;
		TreeNode* pre;

		while(cur){
			if(!cur->left){
				ret.push_back(cur->val);
				cur = cur->right;
				continue;
			}
			// find predecessor
			pre = cur->left;
			while(pre->right && pre->right != cur)
				pre = pre->right;
			if(!pre->right){
				pre->right = cur;
				cur = cur->left;
			}
			else{
			    pre->right = NULL;
				ret.push_back(cur->val);
				cur = cur->right;
			}
		}
		return ret;
    }
};
