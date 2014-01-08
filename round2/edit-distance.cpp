class Solution {
public:
	int minDistance(string word1, string word2){
		if(word1.empty())
			return word2.size();
		if(word2.empty())
			return word1.size();
		int m = word1.size();
		int n = word2.size();
		vector<vector<int> > d(m+1, vector<int>(n+1, 0));
		int i, j;
		for(j = 1; j <= n; j++)
			d[0][j] = j;
		for(i = 1; i <= m; i++)
			d[i][0] = i;

		for(i = 1; i <= m; i++){
			for(j = 1; j <= n; j++){
				if(word1[i] == word2[j])
					d[i][j] = d[i-1][j-1];
				else
					d[i][j] = 1 + min(d[i-1][j-1], min(d[i][j-1], d[i-1][j]));
			}
		}
		return d[m][n];
	}			
};
