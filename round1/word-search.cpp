class Solution {
public:
	
	bool helper(vector<vector<bool> >&visited, vector<vector<char>> &board, string &word, int i, int j, int m, int n, int index, int e){
		if(index > e)
			return true;
		if(i < 0 || i >= m || j < 0 || j >= n)
			return false;

		if(visited[i][j] || board[i][j] != word[index])
			return false;

		//set visited flag
		visited[i][j] = true;
		if(helper(visited, board, word, i, j+1, m, n, index+1, e))
			return true;
		if(helper(visited, board, word, i, j-1, m, n, index+1, e))
			return true;
		if(helper(visited, board, word, i+1, j, m, n, index+1, e))
			return true;
		if(helper(visited, board, word, i-1, j, m, n, index+1, e))
			return true;

		//reset visited flag
		visited[i][j] = false;
		return false;
	}

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		if(word.empty())
			return true;
		if(board.empty())
			return false;

		int index = 0;
		int e = word.size()-1;
		int i, j;
		int m = board.size();
		int n = board[0].size();
		
		vector<vector<bool> > visited(m, vector<bool>(n, false));
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				if(helper(visited, board, word, i, j, m, n, index, e))
					return true;
			}
		}
		return false;
    }
};
