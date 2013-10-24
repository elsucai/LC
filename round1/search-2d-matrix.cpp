class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		// it is actually a sorted array
		
		if(matrix.empty())
			return false;

		int m = matrix.size();
		int n = matrix[0].size();
		
		if(n == 0)
			return false;

		int i, j, mid, x, y;
		i = 0;
		j = m*n-1;
		
		while(i <= j){
			mid = i+(j-i)/2;
			x = mid / n;
			y = mid % n;
			if(matrix[x][y] == target)
				return true;
			else if(matrix[x][y] < target){
				i = mid+1;
			}
			else
				j = mid-1;
		}
		return false;
    }
};
