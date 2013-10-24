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
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		TreeLinkNode *head, *pre, *parent;
		if(!root)
			return;

		parent = root;
		head = pre = root->left;

		while(parent){
			if(!head)
				return;
			if(pre == parent->left){
				pre->next = parent->right;
				pre = pre->next;
			}
			else{
				// pre is a right child
				parent = parent->next;
				if(parent){
					pre->next = parent->left;
					pre = pre->next;
				}
				else{
					//move to next level
					parent = head;
					head = pre = parent->left;
				}
			}
		}
    }
};
