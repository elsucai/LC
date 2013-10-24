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
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!head)
			return head;
		ListNode* pre, *s, *e;
		s = e = head;
		pre = NULL;
		if(n == 0)
			return head;
		int i = 1;
		for(s = e = head; i < n; i++){
			if(!e->next)
				return head;
			e = e->next;
		}
		
		// move s and e at the same pace
		while(e->next){
			pre = s;
			s = s->next;
			e = e->next;
		}
		
		// delete s
		// check if we delete the first one
		if(!pre){
			if(!s->next)
				return NULL;
			return s->next;
		}
		pre->next = s->next;
		return head;
    }
};