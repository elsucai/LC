class Solution {
public:
    int numDistinct(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		int m = S.size();
		int n = T.size();
		vector<vector<int> > D(m+1, vector<int>(n+1, 0));
		int i,j;
		for(i = 0; i <= m; i++)
			D[i][n] = 1;
		for(j = 0; j < n; j++)
			D[m][j] = 0;
			
		for(i  = m-1; i >= 0; i--){
			for(j = n-1; j >= 0; j--){
				if(S[i] == T[j]){
					D[i][j] = D[i+1][j+1] + D[i+1][j];
				}
				else
					D[i][j] = D[i+1][j];
			}
		}
		
		return D[0][0];
    }
};