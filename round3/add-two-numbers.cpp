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
		ListNode* head, *pre;
		head = pre = new ListNode(0);
		int sum, carry;
		sum = carry = 0;
		for(; l1 && l2; l1=l1->next, l2 = l2->next){
			sum = l1->val+l2->val+carry;
			carry = sum/10;
			sum = sum%10;
			pre->next = new ListNode(sum);
			pre = pre->next;
		}
		if(l2)
			swap(l1, l2);
		for(; l1; l1 = l1->next){
			sum = l1->val+carry;
			carry = sum/10;
			sum = sum%10;
			pre->next = new ListNode(sum);
			pre = pre->next;
		}
		if(carry > 0){
			pre->next = new ListNode(carry);
		}
		return head->next;
    }
};
