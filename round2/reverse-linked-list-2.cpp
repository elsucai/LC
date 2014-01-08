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
		ListNode* pre, *cur, *next;
		if(s == e)
			return;
		e->next = NULL;
		pre = NULL;
		cur = s;

		while(cur){
			next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
	}

    ListNode *reverseBetween(ListNode *head, int m, int n) {
		if(!head || !head->next || m == n || m > n)
			return head;

		ListNode* begin, *end, *s, *e;
		begin = end = s = e = NULL;
		int i;
		// find s
		for(i = 1, s = head; i < m; i++){
			begin = s;
			if(!s->next)
				return head;
			s = s->next;
		}
		// find e
		for(i = 1, e = s ; i <= n-m; i++){
			if(!e->next)
				return head;
			e = e->next;
		}
		end = e->next;

		reverse(s, e);
		if(begin)
			begin->next = e;
		else
		    head = e;
		if(end)
			s->next = end;
		return head;
    }
};
