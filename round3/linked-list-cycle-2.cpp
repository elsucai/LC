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
    ListNode *detectCycle(ListNode *head) {
		if(!head)
			return NULL;
		ListNode* slow, *fast;
		slow = fast = head;

		do{
			if(!fast->next || !fast->next->next)
				return NULL;
			fast = fast->next->next;
			slow = slow->next;
		}while(fast != slow);

		slow = head;
		while(fast != slow){
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
    }
};
