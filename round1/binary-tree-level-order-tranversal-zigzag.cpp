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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		bool right2left = false;
		vector<vector<int>> ret;
		stack<TreeNode*> sa;
		stack<TreeNode*> sb;

		if(!root)
			return ret;
		sa.push(root);
		TreeNode* cur;
		vector<int> tmp;
		bool done = false;
		
		while(!done){
			while(!sa.empty()){
				cur = sa.top();
				sa.pop();
				tmp.push_back(cur->val);
				if(right2left){
					if(cur->right)
					sb.push(cur->right);
					if(cur->left)
						sb.push(cur->left);
				}
				else{
					if(cur->left)
						sb.push(cur->left);
					if(cur->right)
						sb.push(cur->right);
				}
			}
			//insert level
			ret.push_back(tmp);
			tmp.clear();
			if(sb.empty())
				done = true;
			right2left = !right2left;
			swap(sa,sb);
		}
		return ret;
    }
};
