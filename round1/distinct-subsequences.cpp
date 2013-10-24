class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
		if(S.empty())
			return 0;
		if(S.size() < T.size())
			return 0;

		int m = S.size();
		int n = T.size();

		int** D = new int*[m+1];
		for(int i = 0; i <= m; i++)
			D[i] = new int[n+1];
		for(int i = 0; i <= m; i++)
			D[i][n] = 1;
		for(int j = 0; j <= n-1; j++)
			D[m][j] = 0;

		if(S[m-1] == T[n-1])
			D[m-1][n-1] = 1;
		else
			D[m-1][n-1] = 0;

		for(int j = n - 1; j >= 0; j--){
			for(int i = m - 1; i >= 0; i--){
				D[i][j] = D[i+1][j];
				if(S[i] == T[j]){
					D[i][j] += D[i+1][j+1];
				}
			}
		}
		int ret = D[0][0];
		for(int i = 0; i < m+1; i++)
			delete[] D[i];
		delete[] D;

		return ret;
    }
};
