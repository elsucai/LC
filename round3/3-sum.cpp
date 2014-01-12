class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > ret;
		vector<int> tmp;
		if(num.size() < 3)
			return ret;
		sort(num.begin(), num.end());
		int first, s, e;
		int two_sum, cursum;
		for(first = 0; first < num.size()-2; ){
			two_sum = -num[first];
			for(s = first+1, e = num.size()-1; s < e;){
				cursum = num[s] + num[e];
				if(cursum == two_sum){
					tmp.clear();
					tmp.push_back(num[first]);
					tmp.push_back(num[s]);
					tmp.push_back(num[e]);
					ret.push_back(tmp);
					s++;
					while(s < e && num[s] == num[s-1])
						s++;
					e--;
					while(e > s && num[e] == num[e+1])
						e--;
				}
				else if(cursum < two_sum){
					s++;
					while(s < e && num[s] == num[s-1])
						s++;
				}
				else{
					e--;
					while(e > s && num[e] == num[e+1])
						e--;
				}
			}
			// move to next first element
			first++;
			while(first < num.size()-2 && num[first] == num[first-1])
				first++;
		}
		return ret;
    }
};
