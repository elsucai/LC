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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

		ListNode *pre, *head;
		pre = head = NULL;
	
		if(!l1)
			return l2;
		if(!l2)
			return l1;
				
		while(l1 && l2){
			if(l1->val > l2->val)
				swap(l1, l2);
			
			// l1->val is always less
			if(!pre){
				head = pre = l1;
			}
			else{
				pre->next = l1;
				pre = l1;
			}

			l1 = l1->next;
		}

		if(l2){
			pre->next = l2;
		}

		return head;
    }
};
