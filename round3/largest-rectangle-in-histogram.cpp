class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
		if(height.empty())
			return 0;
		stack<int> h;
		stack<int> index;
		int max_area = 0;
		int i, pre_index, pre_h;
		for(i = 0; i < height.size(); i++){
			if(h.empty() || height[i] >= h.top()){
				h.push(height[i]);
				index.push(i);
			}
			else{
				// height[i] < previous in the stack
				while(!h.empty() && height[i] < h.top()){
					pre_index = index.top();
					pre_h = h.top();
					index.pop();
					h.pop();
					max_area = max(max_area, pre_h * (i - pre_index));
				}
				h.push(height[i]);
				index.push(pre_index);
			}
		}
		while(!h.empty()){
			pre_index = index.top();
			pre_h = h.top();
			index.pop();
			h.pop();
			max_area = max(max_area, pre_h * (i - pre_index));
		}
		return max_area;
    }
};
