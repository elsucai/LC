class Solution {
public:
/*
	int helper(set<int> &hs, int n, int step){
		int cnt = 0;
		while(hs.find(n) != hs.end()){
			cnt++;
			hs.erase(n);
			n += step;
		}
		return cnt;
	}

	int find_longest_consecutive_seq(vector<int> &valid){
		if(valid.empty())
			return 0;
		set<int> hs;
		for(int i = 0; i < valid.size(); i++)
			hs.insert(valid[i]);

		int max = 0;
		int cur;

		for(int i = 0; i < valid.size(); i++){
			cur = helper(hs, valid[i], 1);	
			cur += helper(hs, valid[i]-1, -1);
			if(max < cur)
				max = cur;
		}
		return max;
	}

    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
		stack<char> par;
		stack<int> index;
		vector<int> valid;

		for(int i = 0; i < s.size(); i++){
			if(par.empty() || !(s[i] == ')' && par.top() == '(')){
				par.push(s[i]);
				index.push(i);
			}
			else{
				// need to pair
				valid.push_back(index.top());
				valid.push_back(i);

				index.pop();
				par.pop();
			}
		}

		return find_longest_consecutive_seq(valid);
    }
	*/
	
	int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
		stack<int> left_index;
		int max = 0;
		int index_before_valid_seq = -1;
		int cur;

		for(int i = 0; i < s.size(); i++){
			if(s[i] == '(')
				left_index.push(i);
			else{
				if(left_index.empty()){
					index_before_valid_seq = i;
				}
				else{
					left_index.pop();
					if(!left_index.empty())
						cur = (i -  left_index.top());
					else
						cur = i - index_before_valid_seq;
					if(max < cur)
						max = cur;
				}
			}
		}
		
		return max;
    }

};
