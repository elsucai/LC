class Solution {
public:

	typedef struct _s{
		int w;
		int h;
	}area;

    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(matrix.empty())
			return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		
		vector< vector<area> > D(m+1, vector<area>(n+1));	// maximum area with matrix[i][j] as the top left element
		vector< vector<int> > W(m, vector<int> (n, 0));	// maximum single line area starting with matrix[i][j]
		vector< vector<int> > H(m, vector<int> (n, 0));	//maximum single column area starting with matrix[i][j]
		
		int q;
		int i, j;
		int gmax = 0;
		for(i = 0; i < m; i++){
			q = 0;
			for(j = n-1; j >= 0; j--){
				if(matrix[i][j] == '0'){
					W[i][j] = 0;
				}
				else{
					W[i][j] = 1 + q;
				}
				q = W[i][j];
			}
		}
		
		for(j = 0; j < n; j++){
			q = 0;
			for(i = m-1; i >= 0; i--){
				if(matrix[i][j] == '0'){
					H[i][j] = 0;
				}
				else{
					H[i][j] = 1 + q;
				}
				q = H[i][j];
			}
		}
		
		for(i = 0; i <= m; i++)
			D[i][n].w = D[i][n].h = 0;
		for(j = 0; j <= n; j++)
			D[m][j].w = D[m][j].h = 0;
		
		int cur;
		for(i = m-1; i >= 0; i--){
			for(j = n-1; j >= 0; j--){
				//compute D
				if(matrix[i][j] == '0')
					D[i][j].w = D[i][j].h = 0;
				else{
					D[i][j].w = W[i][j];
					D[i][j].h = 1;
					cur = H[i][j];
					if(W[i][j] < H[i][j]){
						D[i][j].h = H[i][j];
						D[i][j].w = 1;
					}
					cur = min(W[i][j], D[i+1][j].w) * (1 + D[i+1][j].h);
					if(cur > D[i][j].w * D[i][j].h){
						D[i][j].w = min(W[i][j], D[i+1][j].w);
						D[i][j].h = 1 + D[i+1][j].h;
					}
					cur = min(H[i][j], D[i][j+1].h) * (1 + D[i][j+1].w);
					if(cur > D[i][j].w * D[i][j].h){
						D[i][j].w = 1 + D[i][j+1].w;
						D[i][j].h = min(H[i][j], D[i][j+1].h);
					}
				}
				gmax = max(gmax, D[i][j].w * D[i][j].h);
			}
		}
		return gmax;
    }
};
