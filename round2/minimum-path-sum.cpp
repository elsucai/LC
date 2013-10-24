class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(grid.empty())
			return 0;
			
		int m = grid.size();
		int n = grid[0].size();
		
		vector<vector<int> > D(2, vector<int>(n+1, INT_MAX));
		int cur_row = m-1;
		int cur_dindex = 0;
		D[1][n-1] = 0;
		
		int i, j;
		for(cur_row = m-1; cur_row >= 0; cur_row--){
			for(j = n-1; j >= 0; j--){
				D[cur_dindex][j] = min(D[cur_dindex][j+1], D[(cur_dindex+1)%2][j]) + grid[cur_row][j];
			}
			cur_dindex = (cur_dindex+1)%2;
		}
		return D[(cur_dindex+1)%2][0];
    }
};