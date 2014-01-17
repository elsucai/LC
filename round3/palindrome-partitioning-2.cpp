class Solution {
public:
    int minCut(string s) {
		if(s.size() <= 1)
			return 0;
		int n = s.size();
		vector<int> D(n, INT_MAX);
		vector<vector<bool> > palindrome(n, vector<bool>(n, true));
		D[n-1] = 0;

		int i, j;
		for(i = n-2; i >= 0; i--){
			for(j = n-1; j > i; j--){
				palindrome[i][j] = s[i] == s[j] ? palindrome[i+1][j-1]: false;
			}
		}

		for(i = n-2; i >= 0; i--){
			if(palindrome[i][n-1])
				D[i] = 0;
			else{
				for(j = i; j < n-1; j++){
					if(palindrome[i][j]){
						D[i] = min(D[i], 1+D[j+1]);
					}
				}
			}
		}

		return D[0];
    }
};
