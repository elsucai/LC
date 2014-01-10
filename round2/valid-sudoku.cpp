class Solution {
public:
	bool isvalid(vector<vector<char> > &board, vector<vector<bool> > &row_free, vector<vector<bool> > &col_free, vector<vector<bool> > &sqr_free, int i, int j){
		if(board[i][j] == '.')
			return true;
		int val = board[i][j] - '1'; // 0 -- 8
		int si = i/3;
		int sj = j/3;

		if(!row_free[i][val] || !col_free[j][val] || !sqr_free[si*3+sj][val])
			return false;
		row_free[i][val] = col_free[j][val] = sqr_free[si*3+sj][val] = false;
		return true;
	}

    bool isValidSudoku(vector<vector<char> > &board) {
		vector<vector<bool> > row_free(9, vector<bool>(9, true));        
		vector<vector<bool> > col_free(9, vector<bool>(9, true));        
		vector<vector<bool> > sqr_free(9, vector<bool>(9, true));

		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(!isvalid(board, row_free, col_free, sqr_free, i, j))
					return false;
			}
		}
		return true;
    }
};
