class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        int m = s1.size();
		int n = s2.size();
		if(m+n != s3.size())
			return false;
		
		vector<vector<bool> > D(m+1, vector<bool>(n+1, false));
		D[m][n] = true;
		
		int i, j, k;
		for(j = n-1; j >= 0; j--){
			k = m+j;
			if(s2[j] != s3[k]){
				D[m][j] = false;
			}
			else{
				D[m][j] = D[m][j+1];
			}
		}
		
		for(i = m-1; i >= 0; i--){
			k = i+n;
			if(s1[i] != s3[k]){
				D[i][n] = false;
			}
			else{
				D[i][n] = D[i+1][n];
			}
		}
		
		for(i = m-1; i >= 0; i--){
			for(j = n-1; j >= 0; j--){
				k = i+j;
				if(s1[i] != s3[k] && s2[j] != s3[k]){
					D[i][j] = false;
				}
				else{
					if(s1[i] == s3[k]){
						D[i][j] = D[i][j] || D[i+1][j];
					}
					if(!D[i][j]){
						if(s2[j] == s3[k]){
							D[i][j] = D[i][j] || D[i][j+1];
						}
					}
				}
			}
		}
		
		return D[0][0];
    }
};