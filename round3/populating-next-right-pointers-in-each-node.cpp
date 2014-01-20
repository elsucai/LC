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
		if(!root)
			return;
		TreeLinkNode* p, *first, *cur, *next;
		p = root;
		first = cur = p->left;
		while(first){
			while(cur){
				if(cur == p->left)
					next = p->right;
				else{
					p = p->next;
					if(p)
						next = p->left;
					else
						next = NULL;
				}
				cur->next = next;
				cur = next;
			}
			p = first;
			first = first->left;
			cur = first;
		}
    }
};
