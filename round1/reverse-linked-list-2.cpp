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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(!head)
			return NULL;

		ListNode *next, *newtail, *pre, *s, *tmp;
		pre = NULL;
		tmp = NULL;
		s = head;
		int i;
		for(i = 1; i <= m-1; i++){
			tmp = s;
			s = s->next;
		}

		newtail = s;

		for(i = 1; i <= n-m+1; i++){
			next = s->next;
			s->next = pre;
			pre = s;
			s = next;
		}

		// s is the beginning of the rest list
		if(!tmp)
			head = pre;
		else
			tmp->next = pre;

		newtail->next = s;
		return head;
    }
};
