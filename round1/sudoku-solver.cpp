#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
				
	bool set_flag(int i, int j, vector<vector<char> > &board, char val, vector<vector<bool> > &row_free, vector<vector<bool> > &col_free, vector<vector<bool> > &sq_free){
		int x = val-'1';
		if(!row_free[i][x] || !col_free[j][x])
			return false;
		int sq = i/3 * 3 + j/3;
		if(!sq_free[sq][x])
			return false;
		
		//set
		board[i][j] = val;
		row_free[i][x] = col_free[j][x] = sq_free[sq][x] = false;
		
		return true;
	}

				
	bool find_next(int i, int j, vector<vector<char> > &board, vector<vector<bool> > &row_free, vector<vector<bool> > &col_free, vector<vector<bool> > &sq_free){
		int val;
		char start;
		if(board[i][j] == '.'){
			val = -1;
			start = '1';
		}
		else{
			val = board[i][j] - '1';
			start = board[i][j]+ 1;
		}

		if(start != '1'){
			// reset current cell
			row_free[i][val] = col_free[j][val] = true;
			sq_free[i/3*3+j/3][val] = true;
			board[i][j] = '.';
		}

		for(char x = start; x <= '9'; x++){
			if(set_flag(i, j, board, x, row_free, col_free, sq_free))
				return true;
		}
		return false;
	}
    
	void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		stack<int> pre_i;
		stack<int> pre_j;
		unordered_set<int> fixed;

		int i, j;
		vector<vector<bool> > row_free(9, vector<bool>(9, true));
		vector<vector<bool> > col_free(9, vector<bool>(9, true));
		vector<vector<bool> > sq_free(9, vector<bool>(9, true));

		for(i = 0; i < 9; i++){
			for(j = 0; j < 9; j++){
				if(board[i][j] == '.')
					continue;
				if(!set_flag(i, j, board, board[i][j], row_free, col_free, sq_free))
					return;
				fixed.insert(i*9+j);
			}
		}

		// start to fill the empty cells
		int index;
		for(i = 0; i < 9; ){
			for(j = 0; j < 9; ){
				index = i*9+j;
				if(fixed.find(index) != fixed.end()){
					j++;
					continue;
				}
				// try to fill cell i, j
				if(!find_next(i, j, board, row_free, col_free, sq_free)){
					// rewind back to previous cell
					if(pre_i.empty()){
						// no answer can be found
						return;
					}
					i = pre_i.top();
					j = pre_j.top();
					pre_i.pop();
					pre_j.pop();
				}
				else{
					pre_i.push(i);
					pre_j.push(j);
					j++;
				}
			}
			i++;
		}
    }
};

int main(){
	vector<vector<char> > board(9, vector<char>(9, '.'));
/*
	board[0][2]= '9';
	board[0][3]= '7';
	board[0][4]= '4';
	board[0][5]= '8';
	
	board[1][0]= '7';
	
	board[2][1]= '2';
	board[2][3]= '1';
	board[2][5]= '9';
	
	board[3][2]= '7';
	board[3][6]= '2';
	board[3][7]= '4';
	
	board[4][1]= '6';
	board[4][2]= '4';
	board[4][4]= '1';
	board[4][6]= '5';
	board[4][7]= '9';

	board[5][1]= '9';
	board[5][2]= '8';
	board[5][6]= '3';
	
	board[6][3]= '8';
	board[6][5]= '3';
	board[6][7]= '2';
	
	board[7][8]= '6';
	
	board[8][3]= '2';
	board[8][4]= '7';
	board[8][5]= '5';
	board[8][6]= '9';
*/	
	Solution s;
	
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout<<board[i][j]<<' ';
		}
		cout<<endl;
	}
	
	s.solveSudoku(board);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout<<board[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
