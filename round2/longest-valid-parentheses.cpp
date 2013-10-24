class Solution {
public:
    int longestValidParentheses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		int longest = 0;
	
		stack<int> possible_leftmost;
		int index_bef_leftmost_valid_start = -1;
		
		int i, curlen;
		for(i = 0; i < s.size(); i++){
			if(s[i] == '('){
				possible_leftmost.push(i);
			}
			else{
				if(possible_leftmost.empty()){
					index_bef_leftmost_valid_start = i;
				}
				else{
					possible_leftmost.pop();
					if(!possible_leftmost.empty()){
						curlen = i - possible_leftmost.top();
					}
					else
						curlen = i - index_bef_leftmost_valid_start;
					// update longest
					if(longest < curlen)
						longest = curlen;
				}
			}
		}
		
		return longest;
    }
};