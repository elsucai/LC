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
/*	
	ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode *pre, *cur, *s, *e, *remain, *next;
		if(!head || !head->next || k <= 1)
			return head;
		int i;
		for(i = 1, s = e = head; i < k; i++){
			if(!e->next)
				return head;
			e = e->next;
		}
		remain = e->next;
		e->next = NULL;
		// reverse [s,e]
		pre = NULL;
		cur = s;
		while(cur){
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		s->next = reverseKGroup(remain, k);
		return e;
    }
*/

	void reverse(ListNode* s){
		ListNode* pre, *cur, *next;
		pre = NULL;
		cur = s;
		while(cur){
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
	}

    ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode *pre, *cur, *s, *e, *remain;
		if(!head || !head->next || k <= 1)
			return head;
		int i;
		s = e = head;
		pre = NULL;

		while(s){
			for(i = 1, e = s; i < k; i++){
				if(!e->next)
					return head;
				e = e->next;
			}
			remain = e->next;
			e->next = NULL;
			reverse(s);
			if(!pre)
				head = e;
			else
				pre->next = e;
			s->next = remain;

			pre = s;
			s = remain;
		}

		return head;
    }
};
