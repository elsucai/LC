class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(height.empty())
			return 0;
		stack<int> tall;
		stack<int> index;

		int i = 0;
		int max = 0;
		int size = height.size();
		int pre_height, pre_index, cur_size;

		for(int i = 0; i < size; i++){
			if(tall.empty() || height[i] > tall.top()){
				tall.push(height[i]);
				index.push(i);
			}

			else if(height[i] < tall.top()){
				while(!tall.empty() && height[i] < tall.top()){
					pre_index = index.top();
					pre_height = tall.top();
					index.pop();
					tall.pop();
					cur_size = pre_height * (i - pre_index);
					if(max < cur_size)
						max = cur_size;
				}
				tall.push(height[i]);
				index.push(pre_index);
			}

			// ignore current bar if it equals the previous one
			// the previous one is a better start point
			else
				;
		}

		while(!tall.empty()){
			pre_index = index.top();
			pre_height = tall.top();
			index.pop();
			tall.pop();
			cur_size = pre_height * (size - pre_index);
			if(max < cur_size)
				max = cur_size;
		}

		return max;
	}
};
