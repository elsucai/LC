class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		int m = s1.size();
		int n = s2.size();
		if(m+n != s3.size())
			return false;
		vector<vector<bool> > D(m+1, vector<bool>(n+1, false));
		D[m][n] = true;

		int i, j, k;
		for(j = n-1; j >= 0; j--){
			if(s2[j] != s3[m+j])
				D[m][j] = false;
			else
				D[m][j] = D[m][j+1];
		}
		for(i = m-1; i >= 0; i--){
			if(s1[i] != s3[i+n])
				D[i][n] = false;
			else
				D[i][n] = D[i+1][n];
		}

		for(i = m-1; i >= 0; i--){
			for(j = n-1; j >= 0; j--){
				k = i+j;
				if(s1[i] != s3[k] && s2[j] != s3[k])
					D[i][j] = false;
				else{
					D[i][j] = (s1[i] == s3[k] && D[i+1][j]) || (s2[j] == s3[k] && D[i][j+1]);
				}
			}
		}

		return D[0][0];
    }
};
