class Solution {
public:

	void onebit(int x, int y, int& carry, int& remainder, string &ret){
		int tmp;
		tmp = x + y + carry;
		remainder = tmp % 2;
		carry = tmp / 2;
		if(remainder)
			ret = "1"+ret;
		else
			ret = "0"+ret;
	}
	
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret = "";
		if(a.empty())
			return b;
		if(b.empty())
			return a;
			
		int sizea = a.size();
		int sizeb = b.size();
		
		int i, j, carry, remainder;
		carry = 0;
		
		for(i = sizea-1, j = sizeb-1; i >= 0 && j >= 0; i--, j--){
			onebit(a[i]-'0', b[j]-'0', carry, remainder, ret);
		}
		
		while(i >= 0){
			onebit(a[i]-'0', 0 , carry, remainder, ret);
			i--;
		}
		
		while(j >= 0){
			onebit(b[j]-'0', 0 , carry, remainder, ret);
			j--;
		}
		
		// carry
		if(carry)
			ret = "1"+ret;
		return ret;
    }
};