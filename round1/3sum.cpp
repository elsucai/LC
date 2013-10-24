class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		//sort input vector
		vector<vector<int>> ret;
		sort(num.begin(), num.end());
		int size = num.size();
		if(size < 3)
			return ret;
			
		int i, x, y, sum2, cur_val;
		for(i = 0; i < size - 2; ) {
			// pick num.at(i) ,call 2 sum for the rest
			sum2 = -num.at(i);
			for(x = i+1, y = size - 1; x < y ; ){
				if(num.at(x) + num.at(y) == sum2){
					//found one triplet
					vector<int> tmp;
					tmp.push_back(num.at(i));
					tmp.push_back(num.at(x));
					tmp.push_back(num.at(y));
					ret.push_back(tmp);
					// update pointers
					
					cur_val = num.at(x);
					while(x < y && num.at(x) == cur_val)
						x++;
					cur_val = num.at(y);
					while(x < y && num.at(y) == cur_val)
						y--;
				}
				else if(num.at(x) + num.at(y) > sum2)
					y--;
				else
					x++;
			}
			// current round finished, looking for the next i
			cur_val = num.at(i);
			while(i < size - 2 && num.at(i) == cur_val)
				i++;
		}
        return ret;
    }
};