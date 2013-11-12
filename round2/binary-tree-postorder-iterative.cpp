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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		vector<int> ret;
		stack<TreeNode*> s;
		unordered_set<TreeNode*> visited;

		if(!root)
			return ret;
		s.push(root);
		TreeNode* cur;
		bool print = true;
		while(!s.empty()){
			cur = s.top();
			print = true;
			if(cur->left || cur->right){
				if(cur->right && visited.find(cur->right) == visited.end()){
					s.push(cur->right);
					print = false;
				}
				if(cur->left && visited.find(cur->left) == visited.end()){
					s.push(cur->left);
					print = false;
				}
			}
			if(print){
				s.pop();
				ret.push_back(cur->val);
				visited.insert(cur);
			}
		}

		return ret;
    }
};
