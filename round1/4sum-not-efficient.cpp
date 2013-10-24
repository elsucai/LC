class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		// 4sum O(n^3) complexity
		vector<vector<int>> ret;
		sort(num.begin(), num.end());
		int size = num.size();
		if(size < 4)
			return ret;
		
		int i, j, x, y, cur_val, sum2;
		for(i = 0; i <= size-4; ){
			for(j = i+1; j <= size-3; ){
				// now find 2sum = target - num[i] - num[j]
				sum2 = target - num[i] - num[j];
				for(x = j+1, y = size - 1; x < y; ){
					if(num[x] + num[y] == sum2){
						//found one combination
						vector<int> tmp;
						tmp.push_back(num[i]);
						tmp.push_back(num[j]);
						tmp.push_back(num[x]);
						tmp.push_back(num[y]);
						ret.push_back(tmp);
						cur_val = num[x];
						while(x < size && num[x] == cur_val)
							x++;
						cur_val = num[y];
						while(y >= 0 && num[y] == cur_val)
							y--;
					}
					else if(num[x] + num[y] < sum2){
						cur_val = num[x];
						while(x < size && num[x] == cur_val)
							x++;
					}
					else{
						cur_val = num[y];
						while(y >= 0 && num[y] == cur_val)
							y--;
					}
				}
				// try next num[j]
				cur_val = num[j];
				while(j <= size-3 && num[j] == cur_val)
					j++;
			}
			// try next num[i]
			cur_val = num[i];
			while(i <= size-4 && num[i] == cur_val)
				i++;
		}
		return ret;
    }
};