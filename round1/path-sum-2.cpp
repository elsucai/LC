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
    bool helper(vector<vector<int> > &ret, TreeNode* root, int sum, int start){
    	if(!root)
			return false;
		
		int i, j, size;

		if(!root->left && !root->right){
			if(root->val == sum){
				vector<int> tmp;
				tmp.push_back(root->val);
				ret.push_back(tmp);
                return true;
			}
			return false;
		}

		bool sub;
		//has left or right
		if(root->left){
			sub = helper(ret, root->left, sum - root->val, start);
		}
		if(root->right){
			sub = helper(ret, root->right, sum - root->val, ret.size()) || sub;
		}

		if(sub){
			for(i = start; i < ret.size(); i++){
				ret[i].insert(ret[i].begin(), root->val);
			}
		}
		return sub;
	}

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > ret;
		if(!root)
			return ret;

	
		helper(ret, root, sum, 0);
		return ret;
	}
};