class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(matrix.empty())
			return;
		int m = matrix.size();
		int n = matrix[0].size();
		
		vector<bool> rows(m, false);
		vector<bool> cols(n, false);
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j] == 0)
					rows[i] = cols[j] = true;
			}
		}
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(rows[i] || cols[j])
					matrix[i][j] = 0;
			}
		}
    }
};