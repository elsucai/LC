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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		if(!l1)
			return l2;
		if(!l2)
			return l1;
		int sum = 0;
		int carry = 0;
		ListNode* head, *cur;
		head = cur = new ListNode(0);

		while(l1 && l2){
			sum = l1->val + l2->val + carry;
			carry = sum / 10;
			sum = sum % 10;
			cur->next = new ListNode(sum);
			cur = cur->next;

			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode* remain = l1 ? l1 : l2;
		while(remain){
			sum = remain->val + carry;
			carry = sum / 10;
			sum = sum % 10;
			cur->next = new ListNode(sum);
			cur = cur->next;

			remain = remain->next;
		}
		if(carry > 0){
			cur->next = new ListNode(carry);
		}

		return head->next;
    }
};
