class Solution {
public:
	typedef struct _s{
		int height;
		int index;
	}S;

	static bool comp(S a, S b){
		return a.height < b.height;
	}

    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
		if(height.size() <= 1)
			return 0;
		
		vector<S> sheight;
		for(int i = 0; i < height.size(); i++){
			S tmp;
			tmp.height = height[i];
			tmp.index = i+1;
			sheight.push_back(tmp);
		}
		
		sort(sheight.begin(), sheight.end(), comp);

		int max = 0;
		int cur_max = -1;
		int cur_min = INT_MAX;
		int cur_water = 0;

		for(int i = sheight.size()-1; i >= 0; i--){
			cur_max = cur_max > sheight[i].index ? cur_max : sheight[i].index;
			cur_min = cur_min > sheight[i].index ? sheight[i].index : cur_min;
			cur_water = sheight[i].height*(cur_max - sheight[i].index);
			if(cur_water > max)
				max = cur_water;
			cur_water = sheight[i].height*(sheight[i].index - cur_min);
			if(cur_water > max)
				max = cur_water;
		}

		return max;
    }
};
