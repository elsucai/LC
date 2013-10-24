class Solution {
public:
	
	void DFS(vector<vector<char> > &board, int i, int j, int m, int n){
		if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
			return;
		board[i][j] = 'U';
		DFS(board, i, j-1, m, n);
		DFS(board, i, j+1, m, n);
		DFS(board, i+1, j, m, n);
		DFS(board, i-1, j, m, n);
	}

    void solve(vector<vector<char>> &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(board.empty())
			return;
		int m = board.size();
		int n = board[0].size();
		
		int i, j;
		for(i = 0, j = 0; j < n; j++){
			if(board[i][j] == 'O')
				DFS(board, i, j, m, n);
		}
		for(i = m-1, j = 0; j < n; j++){
			if(board[i][j] == 'O')
				DFS(board, i, j, m, n);
		}
		for(j = 0, i = 0; i < m; i++){
			if(board[i][j] == 'O')
				DFS(board, i, j, m, n);
		}
		for(j = n-1, i = 0; i < m; i++){
			if(board[i][j] == 'O')
				DFS(board, i, j, m, n);
		}
		
		// untrapped 'O's have been changed to 'U'
		// remaining 'O's should be changed to 'X'
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				if(board[i][j] == 'U')
					board[i][j] = 'O';
				else if(board[i][j] == 'O')
					board[i][j] = 'X';
				else
					;
			}
		}
    }
};