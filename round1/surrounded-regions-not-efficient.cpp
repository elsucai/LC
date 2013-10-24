class Solution {
public:
    struct point{
    	int x;
		int y;
		point(int i, int j):x(i), y(j) {}
	};
	
	void helper(vector<vector<char> > &board, vector<point*> &captured, vector<vector<bool> > &visited, int i, int j, int m, int n){
		point* tmp;
		stack<point*> S;
		vector<point*> local;
		bool trapped = true;
		
		tmp = new point(i,j);
		S.push(tmp);
		local.push_back(tmp);
		int x, y;
		while(!S.empty()){
			tmp = S.top();
			x = tmp->x;
			y = tmp->y;
			visited[x][y] = true;
			S.pop();
			
			if(y-1 < 0 || x-1 < 0 || y+1 >= n || x+1 >= m){
				trapped = false;
			}
			
			// left
			if(y-1 >= 0 && board[x][y-1] == 'O' && !visited[x][y-1]){
				tmp = new point(x, y-1);
				S.push(tmp);
				local.push_back(tmp);
			}
			// up
			if(x-1 >= 0 && board[x-1][y] == 'O' && !visited[x-1][y]){
				tmp = new point(x-1, y);
				S.push(tmp);
				local.push_back(tmp);
			}
			//right
			if(y+1 < n && board[x][y+1] == 'O' && !visited[x][y+1]){
				tmp = new point(x, y+1);
				S.push(tmp);
				local.push_back(tmp);
			}
			
			// down
			if(x+1 < m && board[x+1][y] == 'O' && !visited[x+1][y]){
				tmp = new point(x+1, y);
				S.push(tmp);
				local.push_back(tmp);
			}
		}
			
		if(trapped){
			for(int k = 0; k < local.size(); k++){
				captured.push_back(local[k]);
			}
		}
	}
	
	/*
	bool helper(vector<vector<char> > &board, vector<point> &captured, vector<vector<bool> > &visited, int i, int j, int m, int n){
		bool is_trapped = true;
		bool child_trapped;
		
		visited[i][j] = true;
		vector<point> tmptrapped;
		point tmp;
		tmp.x = i;
		tmp.y = j;
		tmptrapped.push_back(tmp);
		
		// left
		if(j-1 < 0){
			is_trapped = false;
		}
		else if(board[i][j-1] == 'O' && !visited[i][j-1]){
			child_trapped = helper(board, tmptrapped, visited, i, j-1, m, n);
			if(!child_trapped)
				is_trapped = false;
		}
		else
			;
		
		// up	
		if(i-1 < 0){
			is_trapped = false;
		}
		else if(board[i-1][j] == 'O' && !visited[i-1][j]){
			child_trapped = helper(board, tmptrapped, visited, i-1, j, m, n);
			if(!child_trapped)
				is_trapped = false;
		}
		else
			;
			
		// right	
		if(j+1 >= n){
			is_trapped = false;
		}
		else if(board[i][j+1] == 'O' && !visited[i][j+1]){
			child_trapped = helper(board, tmptrapped, visited, i, j+1, m, n);
			if(!child_trapped)
				is_trapped = false;
		}
		else
			;
			
		// down	
		if(i+1 >= m){
			is_trapped = false;
		}
		else if(board[i+1][j] == 'O' && !visited[i+1][j]){
			child_trapped = helper(board, tmptrapped, visited, i+1, j, m, n);
			if(!child_trapped)
				is_trapped = false;
		}
		else
			;
			
		if(is_trapped){
			for(int x = 0; x < tmptrapped.size(); x++){
				captured.push_back(tmptrapped[x]);
			}
			return true;
		}
		tmptrapped.clear();
		return false;
	}
	*/
	
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
  
		if(board.empty())
			return;
		int m = board.size();
		int n = board[0].size();
		int i,j;
		vector<point*> captured;
		vector<vector<bool> >visited(m, vector<bool>(n, false));

		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				if(board[i][j] == 'O' && !visited[i][j]){
					helper(board, captured, visited, i, j, m, n);
				}
			}
		}
		
		for(i = 0; i < captured.size(); i++){
			board[captured[i]->x][captured[i]->y] = 'X';
		}
    }
};