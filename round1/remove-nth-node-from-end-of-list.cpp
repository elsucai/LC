/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		ListNode *s, *e, *pre;
		pre = NULL;
		s = head;
		if(!head)
			return head;
		if(n == 0)
			return head;
			
		// special case, remove last element
		if(n == 1){
			for(; s->next != NULL; pre = s, s = s->next)
				;
			//pre is now the last node
			if(!pre)
				return NULL;
			pre->next = NULL;
			return head;
		}

		// use two pointers
		int i;
		for(e = s, i = 1; i < n; i++){
			if(e->next)
				e = e->next;
			else
				return head;	// n is invalid
		}

		while(e->next){
			s = s->next;
			e = e->next;
		}

		// now remove s
		// here s is not the last element
		s->val = s->next->val;
		s->next = s->next->next;
		return head;
    }
};
