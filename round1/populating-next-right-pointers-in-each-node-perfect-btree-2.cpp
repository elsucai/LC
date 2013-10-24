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
		TreeLinkNode* find_next_child(TreeLinkNode* &parent){
			// find first child on the next level, starting from parent
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
			// Start typing your C/C++ solution below
			// DO NOT write int main() function

			TreeLinkNode *head, *pre, *parent, *next;
			if(!root)
				return;
			next = NULL;
			parent = root;
			head = pre = find_next_child(parent);

			while(parent){
				if(!head)
					return;
				if(pre == parent->left){
					if(parent->right){
						next = parent->right;
						pre->next = next;
						pre = next;
						continue;
					}
				}

				parent = parent->next;
				next = find_next_child(parent);
				if(next){
					pre->next = next;
					pre = next;
				}
				else{
					parent = head;
					head = pre = find_next_child(parent);
				}
			}
		}
};
