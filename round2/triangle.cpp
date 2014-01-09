class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		if(triangle.empty())
			return 0;
		int n = triangle.size();
		vector<int> D(n, 0);
		for(int i = 0; i < n; i++)
			D[i] = triangle[n-1][i];

		int row = n-2;
		for(; n >= 2; n--, row--){
			for(int i = 0; i <= n-2; i++){
				D[i] = triangle[row][i] + min(D[i], D[i+1]);
			}
		}
		return D[0];
    }
};
