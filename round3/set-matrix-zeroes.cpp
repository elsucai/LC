class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
		if(matrix.empty() || matrix[0].empty())
			return;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<bool> rowzero(m, false);
		vector<bool> colzero(n, false);
		int i,j;
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				if(matrix[i][j] == 0)
					rowzero[i] = colzero[j] = true;
			}
		}
		
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				if(rowzero[i] || colzero[j])
					matrix[i][j] = 0;
			}
		}
    }
};
