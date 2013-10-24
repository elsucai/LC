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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(!head || head->next == NULL)
        	return head;

		ListNode *s, *e, *pre_s, *pre_e;
		s = head;
		pre_s = NULL;
		e = head->next;
		pre_e = head;
		
		int cur_val = s->val;
		int cnt = 1;
		for(; e != NULL; pre_e = e, e = e->next){
			if(e->val == cur_val)
				cnt++;
			else{
				if(cnt == 1){
					s->val = cur_val;
					pre_s = s;
					s = s->next;
				}
				cur_val = e->val;
				cnt = 1;
			}
		}
		
		if(cnt == 1){
			s->val = cur_val;
			pre_s = s;
			s = s->next;
		}
		
		if(!pre_s)
			return pre_s;
		pre_s->next = NULL;
		return head;
    }
};
