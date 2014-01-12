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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > ret;
		if(!root)
			return ret;
		stack<TreeNode*> cur;
		stack<TreeNode*> next;
		cur.push(root);
		bool l2r = true;
		vector<int> tmp;
		TreeNode* node;
		while(!cur.empty()){
			while(!cur.empty()){
				node = cur.top();
				cur.pop();
				tmp.push_back(node->val);
				// push next level
				if(l2r){
					if(node->left)
						next.push(node->left);
					if(node->right)
						next.push(node->right);
				}
				else{
					if(node->right)
						next.push(node->right);
					if(node->left)
						next.push(node->left);
				}
			}
			// finished one level
			l2r = !l2r;
			ret.push_back(tmp);
			tmp.clear();
			swap(cur, next);
		}
		return ret;
    }
};
