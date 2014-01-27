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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
		if(!head || !head->next)
			return head;

		ListNode* pre, *A, *s, *next;
		pre = A = NULL;
		s = head;
		for(int i = 1; i < m; i++){
			A = s;
			s = s->next;
		}
		
		for(int i = 0; i <= n-m; i++){
			next = s->next;
			s->next = pre;
			pre = s;
			s = next;
		}
		if(A){
			A->next->next = s;
			A->next = pre;
			return head;
		}
		head->next = s;
		return pre;
    }
};
