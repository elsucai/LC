class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
		if(grid.empty() || grid[0].empty())
			return 0;
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int> >D(m+1, vector<int>(n+1, 0));
		D[m-1][n-1] = grid[m-1][n-1];
		int i, j;
		for(j = 0; j <= n; j++)
			D[m][j] = INT_MAX;
		for(i = 0; i <= m; i++)
			D[i][n] = INT_MAX;
		D[m-1][n] = D[m][n-1] = 0;
		
		for(i = m-1; i >= 0; i--){
			for(j = n-1; j >= 0; j--){
				D[i][j] = grid[i][j] + min(D[i][j+1], D[i+1][j]);
			}
		}
		return D[0][0];
    }
};
