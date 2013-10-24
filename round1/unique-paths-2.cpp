class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(obstacleGrid.empty())
			return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if(obstacleGrid[m-1][n-1] == 1)
			return 0;
		vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
		dp[m-1][n] = 1;
		
		int i,j;
		for(i = m-1; i >= 0; i--){
			for(j = n-1; j >= 0; j--){
				if(obstacleGrid[i][j] == 1)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i+1][j] + dp[i][j+1];
			}
		}
		return dp[0][0];
    }
};
