class Solution {
public:
    int numTrees(int n) {
		if(n <= 1)
			return 1;
		vector<int> D(n+1, 0);
		D[0] = D[1] = 1;
		int i, j;
		for(i = 2; i <= n; i++){
			for(j = 0; j < i; j++){
				D[i] += D[j] * D[i-1-j];
			}
		}
		return D[n];
    }
};
