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
    vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ret;
		if(!root)
			return ret;
		stack<TreeNode*> s;
		unordered_set<TreeNode*> printed;
		bool should_print = true;
		s.push(root);

		TreeNode* cur;
		while(!s.empty()){
			should_print = true;
			cur = s.top();
			if(cur->right && printed.find(cur->right) == printed.end()){
				s.push(cur->right);
				should_print = false;
			}
			if(cur->left && printed.find(cur->left) == printed.end()){
				s.push(cur->left);
				should_print = false;
			}
			if(should_print){
				ret.push_back(cur->val);
				s.pop();
				printed.insert(cur);
			}
		}
		return ret;
    }
};
