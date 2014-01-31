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
	vector<TreeNode*> helper(int s, int e){
		vector<TreeNode*> leftret;
		vector<TreeNode*> rightret;
		vector<TreeNode*> ret;
		TreeNode* root;

		int i, l, r;
		if(s > e){
			ret.push_back(NULL);
			return ret;
		}
		if(s == e){
			ret.push_back(new TreeNode(s));
			return ret;
		}
		for(i = s; i <= e; i++){
			leftret = helper(s, i-1);
			rightret = helper(i+1, e);
			for(l = 0; l < leftret.size(); l++){
				for(r = 0; r < rightret.size(); r++){
					root = new TreeNode(i);
					root->left = leftret[l];
					root->right = rightret[r];
					ret.push_back(root);
				}
			}	
		}
		leftret.clear();
		rightret.clear();
		return ret;
	}

    vector<TreeNode *> generateTrees(int n) {
		return	helper(1, n);
    }
};
