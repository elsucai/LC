class Solution {
public:

    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
    
    	// simple recursive method won't work for large test data
		// using dp
		// 3d array can be reduced to 2d -- len(cur_s1) + len(cur_s2) == len(cur_s3)
	
		if(s1.empty()){
			return s2 == s3;
		}
		if(s2.empty()){
			return s1 == s3;
		}

		if(s1.size()+s2.size() != s3.size())
			return false;

		int m = s1.size();
		int n = s2.size();
		vector<vector<bool>> D(m+1, vector<bool>(n+1, false));

		for(int j = 1; j <= n; j++)
			D[0][j] = s2[j-1] == s3[j-1];
		for(int i = 1; i <= m; i++)
			D[i][0] = s1[i-1] == s3[i-1];

		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				D[i][j] = (D[i][j-1] && s2[j-1] == s3[i+j-1]) || (D[i-1][j] && s1[i-1] == s3[i+j-1]);
			}
		}

		return D[m][n];
	}
};
