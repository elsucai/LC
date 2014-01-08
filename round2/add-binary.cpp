class Solution {
public:
    string addBinary(string a, string b) {
		string ret = "";
		if(a.empty())
			return b;
		if(b.empty())
			return a;
		int m = a.size();
		int n = b.size();
		int carry = 0;
		int i, j;
		int sum;
		for(i = m-1, j = n-1; i >= 0 && j >= 0; i--, j--){
			sum = a[i] - '0' + b[j] - '0' + carry;
			carry = sum / 2;
			sum = sum % 2;
			if(sum)
				ret = "1"+ret;
			else
				ret = "0"+ret;
		}
		while(i >= 0){
			sum = a[i--] - '0' + carry;
			carry = sum / 2;
			sum = sum % 2;
			if(sum)
				ret = "1"+ret;
			else
				ret = "0"+ret;
		}
		while(j >= 0){
			sum = b[j--] - '0' + carry;
			carry = sum / 2;
			sum = sum % 2;
			if(sum)
				ret = "1"+ret;
			else
				ret = "0"+ret;
		}

		if(carry){
			ret = "1"+ret;
		}

		return ret;
    }
};
