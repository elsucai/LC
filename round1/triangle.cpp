class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int row;
		int bottom = triangle.size()-1;
		int i, size;
		vector<int> *tmp;
		vector<int> *D = &(triangle[bottom]);
		
		for(row = bottom-1; row >= 0; row--){
			tmp = &(triangle[row]);
			size = (*tmp).size();
			for(i = 0; i < size; i++){
				(*D)[i] = (*tmp)[i] + min((*D)[i], (*D)[i+1]);
			}
		}
		
		return (*D)[0];
    }
};