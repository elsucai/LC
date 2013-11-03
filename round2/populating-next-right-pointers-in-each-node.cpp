/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	TreeLinkNode* find_fc(TreeLinkNode* &parent){
		while(parent){
			if(parent->left)
				return parent->left;
			if(parent->right)
				return parent->right;
			parent = parent->next;
		}
		return NULL;
	}
	
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        TreeLinkNode* parent, *first_child, *cur, *next;
		parent = first_child = cur = next = NULL;
		if(!root)
			return;
		parent = root;
		parent->next = NULL;
		while(parent){
			first_child = find_fc(parent);	//parent will be updated to be the parent of the found first_child
			if(!first_child)
				return;
			cur = first_child;
			while(cur){
				if(cur == parent->left && parent->right)
					next = parent->right;
				else{
					parent = parent->next;
					next = find_fc(parent);
				}
				cur->next = next;
				cur = next;
			}
			parent = first_child;
		}
    }
};