class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> >ret;
		if(num.size() < 4)
			return ret;
		int i, j, s, e;
		int size = num.size();
		int three_target, two_target;
		int sum;
		
		vector<int> tmp;
		sort(num.begin(), num.end());
		
		for(i = 0; i <= size-4; ){
			three_target = target - num[i];
			for(j = i+1; j <= size-3; ){
				two_target = three_target - num[j];
				for(s = j+1, e = size-1; s < e; ){
					sum = num[s] + num[e];
					if(sum == two_target){
						// push to result
						tmp.clear();
						tmp.push_back(num[i]);
						tmp.push_back(num[j]);
						tmp.push_back(num[s]);
						tmp.push_back(num[e]);
						ret.push_back(tmp);
						//move s
						s++;
						while(s < e && num[s] == num[s-1])
							s++;
						//move e
						e--;
						while(s < e && num[e] == num[e+1])
							e--;
					}
					else if(sum < two_target)
						s++;
					else
						e--;
				}
				// update next j
				j++;
				while(j <= size-3 && num[j] == num[j-1])
					j++;
			}
			// update i
			i++;
			while(i <= size-4 && num[i] == num[i-1])
				i++;
		}
		
		return ret;
    }
};