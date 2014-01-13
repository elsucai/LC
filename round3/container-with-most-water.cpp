class Solution {
public:

	struct S{
		int h;
		int index;
		S(int x, int y):h(x),index(y){}
	};

	static bool compare(S a, S b){
		return a.h < b.h;
	}

    int maxArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		int global_area = 0;
		int min_sofar = INT_MAX;
		int max_sofar= INT_MIN;


		vector<S> vs;
		int size = height.size();
		if(size <= 1)
			return 0;
		for(int i = 0; i < size; i++){
			vs.push_back(S(height[i], i));
		}
		sort(vs.begin(), vs.end(), compare);
		for(int i = size-1; i >= 0; i--){
			max_sofar = max(max_sofar, vs[i].index);
			min_sofar = min(min_sofar, vs[i].index);
			global_area = max(global_area, max(vs[i].h * (max_sofar-vs[i].index), vs[i].h * (vs[i].index - min_sofar)));
		}
		return global_area;
	}
};
