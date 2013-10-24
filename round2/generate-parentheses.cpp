class Solution {
public:
	void helper(vector<string> &ret, string &str, int s, int e, int l, int r){
		if(s > e){
			ret.push_back(str);
			return;
		}
		if(r < l || l < 0 || r < 0)
			return;
			
		// try to insert '(' to str[s]
		if(l > 0){
			str[s] = '(';
			helper(ret, str, s+1, e, l-1, r);
		}
		if(r > 0){
			str[s] = ')';
			helper(ret, str, s+1, e, l, r-1);
		}
	}
	
    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

		vector<string> ret;
		if(n <= 0)
			return ret;
		string s = "";
		for(int i = 0; i < 2*n; i++)
			s += "#";
			
		int remaining_l, remaining_r;
		remaining_l = remaining_r = n;
		helper(ret, s, 0, 2*n-1, remaining_l, remaining_r);
		
		return ret;
    }
};