class Solution {
public:
    string addBinary(string a, string b) {
		if(a.empty())
			return b;
		if(b.empty())
			return a;
		string ret = "";
		int m = a.size();
		int n = b.size();
		int carry = 0;
		int i, j, sum;
		string bit = "0";
		for(i = m-1, j = n-1; i >= 0 && j >= 0; i--, j--){
			sum = a[i]-'0'+b[j]-'0'+carry;
			carry = sum/2;
			sum = sum%2;
			bit[0] = '0'+sum;
			ret = bit+ret;
		}
		if(j >= 0){
			swap(a, b);
			i = j;
		}
		while(i >= 0){
			sum = a[i]-'0'+carry;
			carry = sum/2;
			sum = sum%2;
			bit[0] = '0'+sum;
			ret = bit+ret;
			i--;
		}
		if(carry > 0){
			ret = "1"+ret;
		}
		return ret;
    }
};
