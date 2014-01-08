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
		vector<vector<int> >ret;
		bool l_2_r = true;
		if(!root)
			return ret;
		stack<TreeNode*> cur;
		stack<TreeNode*> next;
		vector<int> tmp;
		TreeNode* node;

		cur.push(root);
		while(!cur.empty()){
			while(!cur.empty()){
				node = cur.top();
				cur.pop();
				tmp.push_back(node->val);
				if(l_2_r){
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
			l_2_r = !l_2_r;
			ret.push_back(tmp);
			tmp.clear();
			swap(cur, next);
		}

		return ret;
    }
};
