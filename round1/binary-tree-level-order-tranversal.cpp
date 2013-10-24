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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int>> ret;
		
		if(!root)
			return ret;
		
		queue<TreeNode*> q;
		int cur_level, next_level;
		cur_level = next_level = 0;
		
		TreeNode* cur;
		q.push(root);
		cur_level = 1;
		vector<int> tmp;
		while(!q.empty()){
			cur = q.front();
			q.pop();
			
			tmp.push_back(cur->val);
			cur_level--;
			if(cur->left){
				q.push(cur->left);
				next_level++;
			}
			if(cur->right){
				q.push(cur->right);
				next_level++;
			}
			
			if(cur_level == 0){
				//end of one level
				ret.push_back(tmp);
				tmp.clear();
				cur_level = next_level;
				next_level = 0;
			}
		}
		
		return ret;
    }
};