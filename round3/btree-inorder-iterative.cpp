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
		stack<TreeNode*> s;

		while(1){
			while(cur){
				s.push(cur);
				cur = cur->left;
			}
			if(s.empty())
				return ret;
			cur = s.top();
			s.pop();
			ret.push_back(cur->val);
			cur = cur->right;
		}
    }
};
