class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
		if(nRows == 1)
			return s;
		string ret;
		vector<string> conv(nRows, "");
		int i = 0;
		int index;
		int step = 1;
		for(index = 0, i = 0; i < s.size(); i++, index += step){
			conv[index] += s[i];
			if(index == 0)
				step = 1;
			else if(index == nRows-1)
				step = -1;
			else
				;
		}

		for(i = 0; i < conv.size(); i++){
			ret += conv[i];
		}
		return ret;
    }
};
