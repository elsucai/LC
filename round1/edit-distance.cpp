class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int i, j, ret;
		
		if(word1.empty())
			return word2.size();
		if(word2.empty())
			return word1.size();
		int m = word1.size();
		int n = word2.size();
		
		int** D = new int*[m+1];
		for(int i = 0; i < m+1; i++)
			D[i] = new int[n+1];
		
		for(i = 0; i <= m; i++)
			D[i][0] = i;
		for(j = 0; j <= n; j++)
			D[0][j] = j;
		
		for(i = 1; i <= m; i++){
			for(j = 1; j <= n; j++){
				if(word1[i-1] == word2[j-1])
					D[i][j] = D[i-1][j-1];
				else{
					D[i][j] = min(D[i][j-1] + 1, min(D[i-1][j] + 1, D[i-1][j-1] + 1));
				}
			}
		}
		
		ret = D[m][n];
		for(i = 0; i < m+1; i++)
			delete[] D[i];
		delete[] D;
		
		return ret;
    }
};