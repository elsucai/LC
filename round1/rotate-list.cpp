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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(!head || !(head->next) || k <= 0)
			return head;
		
		ListNode *s, *e, *pre;
		int cnt = 0;

		// first get len
		for(s = head; s; s = s->next)
			cnt++;

		k = k%cnt;
		if(k == 0)
			return head;

		pre = NULL;
		s = e = head;
		for(int i =	1; i <= k-1; i++){
			e = e->next;
		}
		
		while(e->next){
			pre = s;
			s = s->next;
			e = e->next;
		}

		// now s is the new head
		e->next = head;
		pre->next = NULL;
		return s;
    }
};
