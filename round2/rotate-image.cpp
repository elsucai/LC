class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		if(n <= 1)
			return;
		int is, ie, js, je;
		is = js = 0;
		ie = je = n-1;
	
		int i, j;
		while(is < ie && js < je){
			for(j = js, i = ie; i > is && j < je; j++, i--)
				swap(matrix[is][j], matrix[i][js]);
			for(j = je, i = ie; i > is && j > js; j--, i--)
				swap(matrix[ie][j], matrix[i][js]);
			for(j = je, i = is; i < ie && j > js; j--, i++)
				swap(matrix[ie][j], matrix[i][je]);

			is++;
			ie--;
			js++;
			je--;
		}
    }
};
