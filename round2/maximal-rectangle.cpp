class Solution {
public:

	int get_rectanlge(vector<int> &arr){
		stack<int> height;
		stack<int> index;
		int size = arr.size();
		int i, cur, pre_index, pre_height;
		int max_rec = 0;
		int cur_rec = 0;

		for(i = 0; i < size; i++){
			cur = arr[i];
			if(height.empty() || cur >= height.top()){
				height.push(cur);
				index.push(i);
			}
			else if(cur < height.top()){
				while(!height.empty() && cur < height.top()){
					pre_index = index.top();
					pre_height = height.top();
					index.pop();
					height.pop();
					cur_rec = (i - pre_index) * pre_height;
					max_rec = max(max_rec, cur_rec);
				}
				height.push(cur);
				index.push(pre_index);
			}
			else
				;
		}
		while(!height.empty()){
			cur_rec = (size - index.top()) * height.top();
			index.pop();
			height.pop();
			max_rec = max(max_rec, cur_rec);
		}
		return max_rec;
	}

    int maximalRectangle(vector<vector<char> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

		if(matrix.empty() || matrix[0].empty())
			return 0;

		int m = matrix.size();
		int n = matrix[0].size();


		// build new hight matrix
		int i, j;
		vector<vector<int> > height(m, vector<int>(n, 0));
		for(j = 0; j < n; j++){
			height[0][j] = matrix[0][j] == '1' ? 1 : 0;
		}

		for(j = 0; j < n; j++){
			for(i = 1; i < m; i++){
				height[i][j] = matrix[i][j] == '0' ? 0 : 1+height[i-1][j];
			}
		}

		// find maximal rectangle whose base lines in the current row
		int global_max = 0;
		for(i = m-1; i >= 0; i--){
			if(n * (i+1) < global_max)
				return global_max;
			global_max = max(global_max, get_rectanlge(height[i]));
		}
		return global_max;
	}
};
