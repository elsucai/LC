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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode* fast, *slow;
		if(!head)
			return NULL;
		slow = fast = head;
		do{
			if(!fast->next || !fast->next->next)
				return NULL;
			fast = fast->next->next;
			slow = slow->next;
		}while(fast != slow);
		
		// has a cycle
		slow = head;
		while(slow != fast){
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
    }
};