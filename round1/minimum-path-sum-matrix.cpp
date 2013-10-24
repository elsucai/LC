#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
		if(grid.empty())
			return 0;
		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int> > D(m+1, vector<int>(n+1, INT_MAX));
		D[m][n-1] = 0;

		int i, j;
		for(i = m-1; i >= 0; i--){
			for(j = n-1; j >= 0; j--){
				D[i][j] = grid[i][j] + min(D[i][j+1], D[i+1][j]);
			}
		}

		return D[0][0];
    }
};

/*
int main(){
	vector< vector<int> > grid(2, vector<int>(2, 0));
	grid[0][0] = 1;
	grid[0][1] = 2;
	grid[1][0] = 1;
	grid[1][1] = 1;
	int i,j;
	for(i = 0; i <= 1; i++){
		for(j = 0; j <= 1; j++)
			cout<<grid[i][j]<<",";
		cout<<endl;
	}

	Solution S;
	cout<<S.minPathSum(grid)<<endl;
	return 0;
}
*/
