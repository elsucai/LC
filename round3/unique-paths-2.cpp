class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if(obstacleGrid.empty() || obstacleGrid[0].empty())
			return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int> > D(m+1, vector<int>(n+1, 0));
		D[m][n-1] = 1;
		int i, j;
		for(i = m-1; i >= 0; i--){
			for(j = n-1; j >= 0; j--){
				D[i][j] = obstacleGrid[i][j] == 1 ? 0 : D[i][j+1]+D[i+1][j];
			}
		}
		return D[0][0];
    }
};
