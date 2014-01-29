class Solution {
public:
	void init(vector<vector<char> > &board, vector<vector<bool> > &rfree, vector<vector<bool> > &cfree, vector<vector<bool> > &sfree, vector<int> &ei, vector<int> &ej){
		int i, j, val;
		for(i = 0; i < 9; i++){
			for(j = 0; j < 9; j++){
				if(board[i][j] == '.'){
					ei.push_back(i);
					ej.push_back(j);
				}
				else{
					val = board[i][j] - '1';
					rfree[i][val] = cfree[j][val] = sfree[i/3*3+j/3][val] = false;
				}
			}
		}
	}

	int fill_next_valid(vector<vector<char> > &board, vector<vector<bool> > &rfree, vector<vector<bool> > &cfree, vector<vector<bool> > &sfree, int i, int j){
		int val, start;
		start = 0;
		val = -1;
		if(board[i][j] != '.'){
			val = board[i][j] - '1';
			// clear this cell
			rfree[i][val] = cfree[j][val] = sfree[i/3*3+j/3][val] = true;
			board[i][j] = '.';
		}

		for(start = val+1; start <= 8; start++){
			if(rfree[i][start] && cfree[j][start] && sfree[i/3*3+j/3][start]){
				rfree[i][start] = cfree[j][start] = sfree[i/3*3+j/3][start] = false;
				board[i][j] = start+'1';
				return start+1;
			}
		}
		return 0;
	}

	bool helper(vector<vector<char> > &board, vector<vector<bool> > &rfree, vector<vector<bool> > &cfree, vector<vector<bool> > &sfree, vector<int> &ei, vector<int> &ej, int s, int e){
		if(s > e)
			return true;
		while(0 != fill_next_valid(board, rfree, cfree, sfree, ei[s], ej[s])){
			if(helper(board, rfree, cfree, sfree, ei, ej, s+1, e))
				return true;
		}
		return false;
	}

    void solveSudoku(vector<vector<char> > &board) {
		vector<vector<bool> >rfree(9, vector<bool>(9, true));	
		vector<vector<bool> >cfree(9, vector<bool>(9, true));	
		vector<vector<bool> >sfree(9, vector<bool>(9, true));
		
		vector<int> ei;
		vector<int> ej;
		// init
		init(board, rfree, cfree, sfree, ei, ej);
		int size = ei.size();
		helper(board, rfree, cfree, sfree, ei, ej, 0, size-1);
    }
};
