class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if(matrix.empty() || matrix[0].empty())
			return false;
		int m = matrix.size();
		int n = matrix[0].size();
		int size = m*n;

		int s = 0;
		int e = size - 1;
		int mid;
		int i, j;
		while(s <= e){
			mid = s + (e - s)/2;
			// map mid to i, j
			i = mid / n;
			j = mid % n;
			if(matrix[i][j] == target)
				return true;
			if(matrix[i][j] < target)
				s = mid+1;
			else
				e = mid-1;
		}
		return false;
    }
};
