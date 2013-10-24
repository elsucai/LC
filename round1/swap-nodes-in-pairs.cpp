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
			
	void reverse(ListNode* s, ListNode* e){
		ListNode* pre = NULL;
		ListNode* next;
	
		while(s != e){
			next = s->next;
			s->next = pre;
			pre = s;
			s = next;
		}
		s->next = pre;
	}

    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(!head || !(head->next))
			return head;
		ListNode *s, *e, *pre, *next;
		int cnt = 2;
		int i;

		s = e = head;
		pre = NULL;
		while(s){
			for(e = s, i = 1; i < cnt; i++){
				if(e->next)
					e = e->next;
				else
					return head;
			}
			next = e->next;

			// reverse [s -- e]
			reverse(s, e);

			if(!pre)
				head = e;
			else{
				pre->next = e;
			}
			s->next = next;
			pre = s;
			s = next;
		}
		return head;
    }
};
