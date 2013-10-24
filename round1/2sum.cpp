class Solution {
public:
	
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<int> ret;
		if(numbers.size() < 2)
			return ret;
		int size = numbers.size();
		
		unordered_map<int, vector<int>> hm;
		
		for(int i = 0; i < size; i++){
			if(hm.find(numbers[i]) == hm.end()){
				vector<int> tmp;
				hm[numbers[i]] = tmp;
			}
			hm[numbers[i]].push_back(i+1);
			
		}
			
		sort(numbers.begin(), numbers.end());
		
		int i, j, min, max, sum, t;
		for(i = 0, j = size-1; i < j; ){
			sum = numbers[i] + numbers[j];
			if(sum == target){
				if(numbers[i] == numbers[j]){
					min = hm[numbers[i]][0];
					max = hm[numbers[i]][1];
				}
				else{
					min = hm[numbers[i]][0];
					max = hm[numbers[j]][0];
					if(min > max){
						t = min;
						min = max;
						max = t;
					}
				}
				ret.push_back(min);
				ret.push_back(max);
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