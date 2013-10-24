class Solution {
public:
    int minCut(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(s.empty() || s.size() == 1)
			return 0;
			
        int size = s.size();
		vector<vector<bool> > is_palindrome(size, vector<bool>(size, false));
		int i, j, step;
		//build is_palindrome
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
		
		vector<int> D(size+1, size-1);
		D[size] = -1;
		for(i = size-1; i >= 0; i--){
			for(j = i; j <= size-1; j++){
				if(is_palindrome[i][j]){
					D[i] = min(D[i], 1+D[j+1]);
				}
			}
		}
		return D[0];
    }
};