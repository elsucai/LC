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
    vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > ret;
		if(!root)
			return ret;
		vector<int> one_level;
		queue<TreeNode*> cur;
		queue<TreeNode*> next;

		cur.push(root);

		TreeNode* node;
		while(!cur.empty() || !next.empty()){
			while(!cur.empty()){
				node = cur.front();
				cur.pop();
				one_level.push_back(node->val);
				if(node->left)
					next.push(node->left);
				if(node->right)
					next.push(node->right);
			}
			ret.push_back(one_level);
			swap(cur, next);
			one_level.clear();
		}
		return ret;
	}
};
