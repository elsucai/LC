class Solution {
public:
	int helper(vector<int> &height){
		stack<int> h;
		stack<int> index;
		int cur_index, i;
		int global_max = 0;
		int curarea;
		for(i = 0; i < height.size(); i++){
			if(h.empty() || height[i] >= h.top()){
				h.push(height[i]);
				index.push(i);
			}
			else{
				// height[i] < h.top()
				while(!h.empty() && h.top() > height[i]){
					cur_index = index.top();
					curarea = h.top() * (i - cur_index);
					global_max = max(global_max, curarea);
					h.pop();
					index.pop();
				}
				h.push(height[i]);
				index.push(cur_index);
			}
		}
		// deal with remaining bars
		while(!h.empty()){
			curarea = h.top() * (i - index.top());
			global_max = max(global_max, curarea);
			h.pop();
			index.pop();
		}
		return global_max;
	}


    int maximalRectangle(vector<vector<char> > &matrix) {
		if(matrix.empty() || matrix[0].empty())
			return 0;
		
		int m = matrix.size();
		int n = matrix[0].size();

		int i, j;
		vector<vector<int> > heights(m, vector<int>(n, 0));
		// fill first row
		for(j = 0; j < n; j++){
			heights[0][j] = matrix[0][j] == '1' ? 1 : 0;
		}
		for(j = 0; j < n; j++){
			for(i = 1; i < m; i++){
				heights[i][j] = matrix[i][j] == '0' ? 0 : 1 + heights[i-1][j];
			}
		}

		// find max rectangle whose bottom lies in current row
		int global_max = 0;

		for(i = m-1; i >= 0; i--){
			global_max = max(global_max, helper(heights[i]));
		}
		return global_max;
    }
};
