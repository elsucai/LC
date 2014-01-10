class Solution {
public:
	int choose(int n, int k){
		vector<vector<int> > D(n+1, vector<int>(k+1, 1));
		int i, j;
		for(i = 0; i <= n; i++){
			for(j = i+1; j <= k; j++)
				D[i][j] = 0;
		}
		for(i = 1; i <= n; i++)
			D[i][1] = i;

		for(i = 2; i <= n; i++){
			for(j = min(k, i); j >= 2; j--){
				D[i][j] = D[i-1][j] + D[i-1][j-1];
			}
		}
		return D[n][k];
	}

    int uniquePaths(int m, int n) {
		// compute choose n-1 from m+n-2
		// using DP
		
		// (n,k) = (n-1,k) + (n-1,k-1)
		
		return choose(n+m-2, n-1);
    }
};
