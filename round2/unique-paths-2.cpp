class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int> > D(m+1, vector<int>(n+1, 0));
		D[m-1][n] = 1;
		int i, j;
		for(i = m-1; i >= 0; i--){
			for(j = n-1; j >= 0; j--){
				if(obstacleGrid[i][j] == 1)
					D[i][j] = 0;
				else
					D[i][j] = D[i][j+1] + D[i+1][j];
			}
		}
		return D[0][0];
    }
};
