class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		// use O(rowIndex) space
		
		vector<int> ret;
		if(rowIndex < 0)
			return ret;
		
		ret.push_back(1);
		if(rowIndex == 0)
			return ret;
		
		ret.push_back(1);
		if(rowIndex == 1)
			return ret;
			
		int i, j, end, pre_size;
		pre_size = 1;
		for(int r = 2; r <= rowIndex; r++){
			pre_size++;
			ret.push_back(1);
			end = pre_size/2;
			for(j = end; j >= 1; j--)
				ret[j] += ret[j-1];
			j = end+1;
			if(pre_size & 1 == 0)
				end--;
			for(; end > 0; end--, j++)
				ret[j] = ret[end];
		}
		
		return ret;
    }
};