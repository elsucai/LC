class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		if(triangle.empty())
			return 0;
		int rows = triangle.size();
		vector<int> D(rows, 0);
		int i, j;
		for(i = 0; i < rows; i++)
			D[i] = triangle.back()[i];

		for(i = rows-2; i >= 0; i--){
			for(j = 0; j <= i; j++){
				D[j] = triangle[i][j] + min(D[j], D[j+1]);
			}
		}
		return D[0];
    }
};
