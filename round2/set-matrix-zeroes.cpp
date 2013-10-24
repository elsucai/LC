class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		
		// use constant extra space
		// use some elements in the matrix as storage
		
		if(matrix.empty())
			return;
		int m = matrix.size();
		int n = matrix[0].size();
		
		bool zero_row_one = false;
		bool zero_col_one = false;
		int i, j;
		
		for(j = 0; j < n; j++){
			if(matrix[0][j] == 0){
				zero_row_one = true;
				break;
			}
		}
		for(i = 0; i < m; i++){
			if(matrix[i][0] == 0){
				zero_col_one = true;
				break;
			}
		}
		
		for(i = 1; i < m; i++){
			for(j = 1; j < n; j++){
				if(matrix[i][j] == 0){
					matrix[i][0] = matrix[0][j] = 0;
				}
			}
		}
		
		// markers are all set
		for(i = 1; i < m; i++){
			for(j = 1; j < n; j++){
				if(matrix[i][0] == 0 ||  matrix[0][j] == 0){
					matrix[i][j] = 0;
				}
			}
		}
		
		if(zero_row_one){
			for(j = 0; j < n; j++){
				matrix[0][j] = 0;
			}
		}
		if(zero_col_one){
			for(i = 0; i < m; i++){
				matrix[i][0] = 0;
			}
		}
    }
};