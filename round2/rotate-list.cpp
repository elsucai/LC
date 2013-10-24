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
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode* pre, *s, *e;
		if(!head)
			return head;
			
		int len = 0;
		for(s = head; s; s=s->next)
			len++;
		k = k % len;
		if(k == 0)
			return head;
			
		for(s = e = head, len = 1; len < k; len++)
			e = e->next;
			
		pre = NULL;
		while(e->next){
			pre = s;
			s = s->next;
			e = e->next;
		}
		
		// [s -- e] is the new first half
		// pre won't be NULL here
		pre->next = NULL;
		e->next = head;
		return s;
    }
};