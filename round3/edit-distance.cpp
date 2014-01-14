class Solution {
public:
	int minDistance(string word1, string word2){
		if(word1.empty())
			return word2.size();
		if(word2.empty())
			return word1.size();
		int m = word1.size();
		int n = word2.size();
		int i,j;
		vector<vector<int> > D(m+1, vector<int>(n+1, 0));
		for(j = 1; j <= n; j++)
			D[0][j] = j;
		for(i = 1; i <= m; i++)
			D[i][0] = i;

		for(i = 1; i <= m; i++){
			for(j = 1; j <= n; j++){
				if(word1[i-1] == word2[j-1])
					D[i][j] = D[i-1][j-1];
				else
					D[i][j] = 1 + min(D[i-1][j-1], min(D[i-1][j], D[i][j-1]));
			}
		}
		return D[m][n];
	}			
};
