class Solution {
public:

	bool fill_curempty(int curempty, vector<vector<char> > &board, vector<vector<bool> > &rows, vector<vector<bool> > &cols, vector<vector<bool> > &squares){
		int i, j, si, sj;
		i = curempty/9;
		j = curempty%9;
		si = i/3;
		sj = j/3;

		int val = board[i][j] == '.' ? 1 : board[i][j] - '0'+1;
		if(val != 1){
			int ori = board[i][j] - '0';
			rows[i][ori] = cols[j][ori] = squares[si*3+sj][ori] = false;
		}
		// try next val
		for(; val <= 9; val++){
			if(!rows[i][val] && !cols[j][val] && !squares[si*3+sj][val]){
				rows[i][val] = cols[j][val] = squares[si*3+sj][val] = true;
				board[i][j] = '0'+val;
				return true;
			}
		}
		if(board[i][j] != '.'){
			val = board[i][j] - '0';
			rows[i][val] = cols[j][val] = squares[si*3+sj][val] = false;
			board[i][j] = '.';
		}
		return false;
	}
	
	int find_next_empty(vector<int> &empty_index, unordered_map<int, int> &hm, int curempty){
		int index = hm[curempty];
		if(index == empty_index.size()-1)
			return -1;
		return empty_index[index+1];
	}

	bool helper(vector<vector<char> > &board, vector<vector<bool> > &rows, vector<vector<bool> > &cols, vector<vector<bool> > &squares, vector<int> &empty_index, unordered_map<int, int> &hm, int curempty){
	
		int nextempty;
		while(fill_curempty(curempty, board, rows, cols, squares)){
			nextempty = find_next_empty(empty_index, hm, curempty);
			if(-1 == nextempty)
				return true;
			if(helper(board, rows, cols, squares, empty_index, hm, nextempty))
				return true;
		}
		return false;
	}

    void solveSudoku(vector<vector<char> > &board) {
	
		// false means vacancy
		vector<vector<bool> > rows(9, vector<bool>(10, false));
		vector<vector<bool> > cols(9, vector<bool>(10, false));
		vector<vector<bool> > squares(9, vector<bool>(10, false));
		vector<int> empty;
		unordered_map<int, int> hm;

		int i, j, si, sj, index;
		char c;
		for(i = 0, index = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				c = board[i][j];
				if(c == '.'){
					empty.push_back(i*9+j);
					hm[i*9+j] = index;
					index++;
				}
				else{
					rows[i][c-'0'] = true;
					cols[j][c-'0'] = true;
					si = i/3;
					sj = j/3;
					squares[si*3+sj][c-'0'] = true;
				}
			}
		}

		if(empty.empty())
			return;
		helper(board, rows, cols, squares, empty, hm, empty[0]);
    }
};
