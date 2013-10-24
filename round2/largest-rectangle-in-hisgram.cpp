class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		stack<int> H;
		stack<int> I;

		int size = height.size();
		int maxarea = 0;
		int i;

		int cur_h;
		int cur_i;
		int curarea;
		int marker;

		for(i = 0; i < size; i++){
			if(H.empty()){
				H.push(height[i]);
				I.push(i);
			}
			else if(H.top() < height[i]){
				H.push(height[i]);
				I.push(i);
			}
			else if(H.top() > height[i]){
				marker = height[i];
				while(!H.empty() && H.top() >= marker){
					cur_h = H.top();
					cur_i = I.top();
					H.pop();
					I.pop();
				
					curarea = cur_h * (i-cur_i);
					if(maxarea < curarea)
						maxarea = curarea;
				}
				H.push(marker);
				I.push(cur_i);
			}
			else
				;
		}

		while(!H.empty()){
			cur_h = H.top();
			cur_i = I.top();
			H.pop();
			I.pop();

			curarea = cur_h * (i-cur_i);
			if(maxarea < curarea)
				maxarea = curarea;
		}

		return maxarea;
    }
};
