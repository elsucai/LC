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
	TreeLinkNode* get_first_child(TreeLinkNode* &p){
		if(!p)
			return NULL;
		while(p){
			if(p->left)
				return p->left;
			if(p->right)
				return p->right;
			p = p->next;
		}
		return NULL;
	}

    void connect(TreeLinkNode *root) {
		if(!root)
			return;
		TreeLinkNode* p, *first, *cur, *next;
		p = root;
		cur = first = get_first_child(p);
		
		while(first){
			while(cur){
				if(cur == p->left){
					if(p->right)
						next = p->right;
					else{
						p = p->next;
						next = get_first_child(p);
					}
				}
				else{
					p = p->next;
					next = get_first_child(p);
				}
				cur->next = next;
				cur = next;
			}
			p = first;
			cur = first = get_first_child(p);
		}
    }
};
