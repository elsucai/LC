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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> > ret;

		if(!root)
			return ret;
		queue<TreeNode*> cur;
		queue<TreeNode*> next;
		vector<int> tmp;

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
			swap(cur, next);
			tmp.clear();
		}
		//reverse ret
		for(int i = 0, j = ret.size()-1; i < j; i++, j--)
			swap(ret[i], ret[j]);

		return ret;
    }
};
