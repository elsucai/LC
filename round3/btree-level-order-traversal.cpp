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
		vector<int> tmp;
		queue<TreeNode*> cur;
		queue<TreeNode*> next;
		if(!root)
			return ret;
		cur.push(root);

		TreeNode* node;
		while(!cur.empty()){
			while(!cur.empty()){
				node = cur.front();
				cur.pop();
				tmp.push_back(node->val);
				if(node->left)
					next.push(node->left);
				if(node->right)
					next.push(node->right);
			}
			ret.push_back(tmp);
			tmp.clear();
			swap(cur, next);
		}
		return ret;
	}
};
