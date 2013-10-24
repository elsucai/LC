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
			
		int i, j, start;
		for(int r = 2; r <= rowIndex; r++){
			ret.push_back(1);
			i = ret.size()-2;
			start = i - (ret.size()-1)/2;
			for(j = i; j >= start+1; j--)
				ret[j] = ret[j]+ret[j-1];
			
			// r+1 == ret.size() actually 
			if((r+1) % 2 == 1){
				// r+1 is odd
				start = j+2;
			}
			else
				start = j+1;
			for(; start < ret.size(); start++)
				ret[j--] = ret[start];
		}
		
		return ret;
    }
};