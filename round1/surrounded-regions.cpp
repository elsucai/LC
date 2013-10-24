class Solution {
public:
    // run time error for large test
    // could be the stack size constrain
	// no-efficient version works for large test
	// should try to using stack for dfs
	
    void dfs(vector<vector<char> > &board, int i, int j, int m, int n){
		if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == 'X' || board[i][j] == 'D')
			return;
		stack<int> Si;
		stack<int> Sj;
		
		Si.push(i);
		Sj.push(j);
		int ci, cj;
		
		while(!Si.empty()){
			ci = Si.top();
			cj = Sj.top();
			Si.pop();
			Sj.pop();
			board[ci][cj] = 'D';
			// left
			if(cj-1 >= 0 && board[ci][cj-1] == 'O'){
				Si.push(ci);
				Sj.push(cj-1);
			}
			
			// up
			if(ci-1 >= 0 && board[ci-1][cj] == 'O'){
				Si.push(ci-1);
				Sj.push(cj);
			}
			
			// right
			if(cj+1 < n && board[ci][cj+1] == 'O'){
				Si.push(ci);
				Sj.push(cj+1);
			}
			
			// down
			if(ci+1 < m && board[ci+1][cj] == 'O'){
				Si.push(ci+1);
				Sj.push(cj);
			}
		}
	}	
	
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
  
		if(board.empty())
			return;
		int m = board.size();
		int n = board[0].size();
		
		// scan from 'O' on edges
		// all connected nodes are marked 'D'
		int i,j;
		for(i = 0; i < m; i++){
			if(board[i][0] == 'O')
				dfs(board, i, 0, m, n);
			if(board[i][n-1] == 'O')
				dfs(board, i, n-1, m, n);
		}
		
		for(j = 1; j < n-1; j++){
			if(board[0][j] == 'O')
				dfs(board, 0, j, m, n);
			if(board[m-1][j] == 'O')
				dfs(board, m-1, j, m, n);
		}
		
		// scan board, change 'D' to 'O' and 'O' to 'X'
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				if(board[i][j] == 'O')
					board[i][j] = 'X';
				else if(board[i][j] == 'D')
					board[i][j] = 'O';
				else
				;
			}
		}
	
    }
};