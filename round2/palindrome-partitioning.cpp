class Solution {
public:
	void helper(vector<vector<string> > &ret, vector<vector<bool> > &is_palindrome, vector<string> &one, string &str, int s, int e){
		if(s > e){
			ret.push_back(one);
			return;
		}
		int i;
		for(i = 0; i < e-s+1; i++){
			if(is_palindrome[s][s+i]){
				one.push_back(str.substr(s, i+1));
				helper(ret, is_palindrome, one, str, s+i+1, e);
				one.erase(one.end()-1);
			}
		}
	}
	
	
    vector<vector<string>> partition(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		vector<vector<string> > ret;
		vector<string> one;
		if(s.empty() || s.size() == 1){
			one.push_back(s);
			ret.push_back(one);
			return ret;
		}
		
		int size = s.size();
		vector<vector<bool> > is_palindrome(size, vector<bool>(size, false));
		int i, j, step;
		//build D
		for(i = 0; i < size; i++){
			is_palindrome[i][i] = true;
		}
		for(i = 0; i < size; i++){
			for(j = 0; j < i; j++){
				is_palindrome[i][j] = true;
			}
		}
		
		for(step = 2; step <= size; step++){
			for(i = 0; i <= size-step; i++){
				is_palindrome[i][i+step-1] = (s[i] == s[i+step-1]) && is_palindrome[i+1][i+step-2];
			}
		}
		
		helper(ret, is_palindrome, one, s, 0, size-1);
		return ret;
    }
};