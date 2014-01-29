class Solution {
public:
	void DFS(vector<vector<char> > &board, int i, int j, int m, int n){
		if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
			return;

		stack<int> si;
		stack<int> sj;
		si.push(i);
		sj.push(j);

		while(!si.empty()){
			i = si.top();
			j = sj.top();
			si.pop();
			sj.pop();
		
			board[i][j] = 'F';
			if(j-1 >= 0 && j-1 < n && board[i][j-1] == 'O'){
				si.push(i);
				sj.push(j-1);
			}
			if(j+1 >= 0 && j+1 < n && board[i][j+1] == 'O'){
				si.push(i);
				sj.push(j+1);
			}
			if(i+1 >= 0 && i+1 < m && board[i+1][j] == 'O'){
				si.push(i+1);
				sj.push(j);
			}
			if(i-1 >= 0 && i-1 < m && board[i-1][j] == 'O'){
				si.push(i-1);
				sj.push(j);
			}
		}
	}

    void solve(vector<vector<char>> &board) {
		if(board.empty() || board[0].empty())
			return;
		int m = board.size();
		int n = board[0].size();
		int i, j;
		
		
		for(j = 0; j < n; j++)
			DFS(board, 0, j, m, n);
		for(j = 0; j < n; j++)
			DFS(board, m-1, j, m, n);
		for(i = 0; i < m; i++)
			DFS(board, i, 0, m, n);
		for(i = 0; i < m; i++)
			DFS(board, i, n-1, m, n);

		
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				if(board[i][j] == 'O')
					board[i][j] = 'X';
				else if(board[i][j] == 'F')
					board[i][j] = 'O';
				else
					;
			}
		}
    }
};
