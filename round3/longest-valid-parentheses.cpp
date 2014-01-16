class Solution {
public:
    int longestValidParentheses(string s) {
		if(s.size() <= 1)
			return 0;

		stack<int> lefts;
		int leftmost = -1;
		int longest = 0;
		int i;

		for(i = 0; i < s.size(); i++){
			if(s[i] == '('){
				lefts.push(i);
			}
			else{
				// must be ')'
				if(lefts.empty())
					leftmost = i;
				else{
					lefts.pop();
					if(lefts.empty()){
						longest = max(longest, i-leftmost);
					}
					else{
						longest = max(longest, i-lefts.top());
					}
				}
			}
		}

		return longest;
    }
};
