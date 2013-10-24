class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		//sort the vector
		sort(num.begin(), num.end());
		int size = num.size();
		int closest = 0;
		
		if(size < 3){
			for(int i = 0; i < size; i++)
				closest += num[i];
			return closest;
		}
		
		int i, x, y, mindiff, curdiff, cur_val;
		mindiff = INT_MAX;
		for(i = 0; i < size; ){
			//assume num[i] is in the final 3 numbers
			// looking for closest 2
			for(x = i+1, y = size - 1; x < y; ){
				if(num[x] + num[y] == target - num[i]){
					// the diff is 0, must be the optimal solution
					return target;
				}
				else{
					curdiff = target - num[i] - num[x] - num[y];
					if(abs(curdiff) < mindiff){
						mindiff = abs(curdiff);
						closest = num[i] + num[x] + num[y];
					}
					
					if(num[x] + num[y] < target - num[i]){
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
			}
			//try next num[i]
			cur_val = num[i];
			while(i < size && num[i] == cur_val)
				i++;
		}
		return closest;
    }
};