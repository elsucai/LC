class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int twotarget;
		int i, s, e;
		int closest;
		int global_mindiff;
		int mindiff, minsum;
		if(num.size() < 3){
			closest = 0;
			for(i = 0; i < num.size(); i++){
				closest += num[i];
			}
			return closest;
		}
		
		sort(num.begin(), num.end());
		int size = num.size();
		int sum, curdiff;
		global_mindiff = INT_MAX;
		for(i = 0; i < size-2; ){
			twotarget = target - num[i];
			mindiff = INT_MAX;
			for(s = i+1, e = size-1; s < e; ){
				sum = num[s]+num[e];
				if(sum == twotarget){
					return target;
				}
				// update mindiff
				curdiff = abs(twotarget - sum);
				if(curdiff < mindiff){
					mindiff = curdiff;
					minsum = sum;
				}
				if(sum < twotarget){				
					// move s
					s++;
					while(s < e && num[s] == num[s-1])
						s++;
				}
				else{
					// move e
					e--;
					while(e > s && num[e] == num[e+1])
						e--;
				}
			}
			//update global_mindiff;
			if(global_mindiff > mindiff){
				global_mindiff = mindiff;
				closest = num[i]+minsum;
			}
			
			// move i
			i++;
			while(i < size-2 && num[i] == num[i-1])
				i++;
		}
		return closest;
    }
};