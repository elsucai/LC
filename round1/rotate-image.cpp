class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(matrix.empty() || matrix.size() == 1)
			return;

		int rs, re, cs, ce, i, c;

		rs = cs = 0;
		re = ce = matrix.size()-1;

		while(rs <= re && cs <= ce){
			if(rs == re)
				return;
			// swap corners
			swap(matrix[rs][cs], matrix[rs][ce]);
			swap(matrix[rs][cs], matrix[re][ce]);
			swap(matrix[rs][cs], matrix[re][cs]);

			// swap edges
			for(i = cs+1, c = 1; i <= ce-1; i++,c++)
				swap(matrix[rs][i], matrix[rs+c][ce]);
			for(i = cs+1, c = 1; i <= ce-1; i++,c++)
				swap(matrix[rs][i], matrix[re][ce-c]);
			for(i = cs+1, c = 1; i <= ce-1; i++,c++)
				swap(matrix[rs][i], matrix[re-c][cs]);

			// update index
			rs++;
			re--;
			cs++;
			ce--;
		}
    }
};
