class Solution {
public:
	int choose(int n, int k){
		vector<vector<int> >D(n+1, vector<int>(k+1, 0));
		int i, j;
		for(i = 0; i <= n; i++)
			D[i][0] = 1;

		for(i = 1; i <= n; i++){
			for(j = 1; j <= min(i, k); j++)
				D[i][j] = D[i-1][j] + D[i-1][j-1]; 
		}
		return D[n][k];
	}

    int uniquePaths(int m, int n) {
		// compute m+n-2 choose m-1
		return choose(m+n-2, min(m,n)-1);
    }
};
