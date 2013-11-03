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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
		ListNode* fast, *slow;
		if(!head || !head->next)
			return false;
		slow = head;
		fast = head->next;
		
		while(fast != slow){
			if(!fast->next || !fast->next->next)
				return false;
			fast = fast->next->next;
			slow = slow->next;
		}
		return true;
    }
};