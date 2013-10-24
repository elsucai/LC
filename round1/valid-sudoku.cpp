class Solution {
public:

	bool check(char x, int i, int j, vector<vector<bool> > &rows, vector<vector<bool> > &cols, vector<vector<bool> > &squares){
		// check if x is valid
		if(x == '.')
			return true;
		if(x < '1' || x > '9')
			return false;
		if(rows[i][x-'0'-1])
			return false;
		if(cols[j][x-'0'-1])
			return false;
		int ni = i/3;
		int nj = j/3;
		int sq = 3*ni+nj;

		if(squares[sq][x-'0'-1])
			return false;
	
		rows[i][x-'0'-1] = true;
		cols[j][x-'0'-1] = true;
		squares[sq][x-'0'-1] = true;

		return true;
	}

    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(board.size() != 9)
			return false;
		if(board[0].size() != 9)
			return false;
		vector<vector<bool> >rows(9, vector<bool>(9, false));
		vector<vector<bool> >cols(9, vector<bool>(9, false));
		vector<vector<bool> >squares(9, vector<bool>(9, false));

		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				if(!check(board[i][j], i, j, rows, cols, squares))
					return false;
			}
		}
		return true;
    }
};
