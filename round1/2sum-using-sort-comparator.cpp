class Solution {
public:
	typedef struct _s{
		int val;
		int index;
	}S;
	
	bool comp(S a, S b){
		return a.val < b.val;
	}
	
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<int> ret;
		if(numbers.size() < 2)
			return ret;
		
		vector<S> co;
		S tmp;
		for(int i = 0; i < numbers.size(); i++){
			tmp.val = numbers[i];
			tmp.index = i;
			co.push_back(tmp);
		}
		
		sort(co.begin(), co.end(), comp);
		
		int i, j, tmp, min, max, sum;
		for(i = 0, j = co.size()-1; i < j; ){
			sum = co[i].val + co[j].val;
			if(sum == target){
				min = co[i].index;
				max = co[j].index;
				if(min > max){
					tmp = min;
					min = max;
					max = tmp;
				}
				ret.push_back(min+1);
				ret.push_back(max+1);
				break;
			}
			else if(sum < target)
				i++;
			else
				j--;
		}
		return ret;
	}
};