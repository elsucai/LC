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
    bool hasCycle(ListNode *head) {
		ListNode* slow, *fast;
		if(!head)
			return false;
		slow = fast = head;
		do{
			if(!fast->next || !fast->next->next)
				return false;
			fast = fast->next->next;
			slow = slow->next;
		}while(fast != slow);
		return true;
    }
};
