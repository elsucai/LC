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
	void helper(ListNode* a, ListNode* b){
		// reverse the list from a to b (inclusive)
		if(a == b){
			a->next = NULL;
			return;
		}
		
		ListNode* s = a;
		ListNode* e = b;
		ListNode* p = s->next;
		ListNode* pre = NULL;
		while(s != e){
			s->next = pre;
			pre = s;
			s = p;
			p = p->next;
		}
		s->next = pre;
	}
	
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(!head || !(head->next) || k <= 1)
			return head;
		
		ListNode *pre, *next, *s, *e;
		s = head;
		pre = NULL;
		int i;
		while(s){
			e = s;
			for(i = 1; i <= k-1; i++){
				if(!(e->next))
					return head;
				e = e->next;
			}
			next = e->next;
			helper(s, e);
			
			if(!pre){
				head = e;
			}
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