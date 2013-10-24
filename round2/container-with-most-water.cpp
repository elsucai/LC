class Solution {
public:
	struct S{
		int h;
		int index;
		S(int x, int y):h(x), index(y) {}
	};

	static bool comp(S* a, S* b){
		return a->h < b->h;
	}

    int maxArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

		vector<S*> arr;
		int i, curarea;
		int size = height.size();
		
		for(i = 0; i < size; i++){
			arr.push_back(new S(height[i], i));
		}
		sort(arr.begin(), arr.end(), comp);

		int imax, imin, maxarea;
		maxarea = INT_MIN;
		imax = INT_MIN;
		imin = INT_MAX;

		// current bar can be the shorter bar of the left or right bar of the largest container
		// look at all bars that are no shorter than current bar
		for(i = size - 1; i >= 0; i--){
			if(arr[i]->index > imax){
				imax = arr[i]->index;
			}
			if(arr[i]->index < imin){
				imin = arr[i]->index;
			}
			
			curarea = arr[i]->h * (imax - arr[i]->index);
			maxarea = max(maxarea, curarea);

			curarea = arr[i]->h * (arr[i]->index - imin);
			maxarea = max(maxarea, curarea);
		}
		
		return maxarea;
    }
};
