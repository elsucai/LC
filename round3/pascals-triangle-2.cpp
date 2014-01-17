class Solution {
public:
    vector<int> getRow(int rowIndex) {
		if(rowIndex < 0)
			return vector<int>();
		vector<int> ret(rowIndex+1, 1);
		if(rowIndex <= 1)
			return ret;
		int stop_index;
		for(int i = 2; i <= rowIndex; i++){
			// fill new row
			stop_index = i - i/2;
			for(int x = i-1; x >= stop_index; x--){
				ret[x] += ret[x-1];
			}
			// fill symmetric
			for(int x = stop_index-1; x > 0; x--)
				ret[x] = ret[i-x];
		}
		return ret;
    }
};
