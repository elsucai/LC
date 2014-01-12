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
		TreeNode* node;
		cur.push(root);
		vector<int> tmp;
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
		// reverse ret
		int i, j;
		for(i = 0, j = ret.size()-1; i < j; i++, j--){
			swap(ret[i] ,ret[j]);
		}
		return ret;
    }
};
