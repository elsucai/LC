class Solution {
public:
    
	string add_string(string &x, string &y){
		if(x == "0")
			return y;
		if(y == "0")
			return x;
		int i, j;
		string sum = "0";
		int carry = 0;
		int tmp;
		string onebit = "0";
        string ret = "";

		for(i = x.size()-1, j = y.size()-1; i >= 0 && j >= 0; i--, j--){
			tmp = (x[i]-'0') + (y[j]-'0') + carry;
			onebit[0] = tmp%10 + '0';
			ret = onebit+ret;
			carry = tmp/10;
		}

		for(; i >= 0; i--){
			tmp = (x[i]-'0') + carry;
			onebit[0] = tmp%10 + '0';
			ret = onebit+ret;
			carry = tmp/10;
		}
		
		for(; j >= 0; j--){
			tmp = (y[j]-'0') + carry;
			onebit[0] = tmp%10 + '0';
			ret = onebit+ret;
			carry = tmp/10;
		}
		
		if(carry > 0){
			onebit[0] = carry+'0';
			ret = onebit+ret;
		}

		return ret;

	}

	string multiply_single_digit(string &x, int d){
		if(d == 0)
			return "0";
		if(d == 1)
			return x;
		if(x == "0")
			return "0";
		if(x == "1")
			return string(1, '0'+d);
		
		string ret = "";
		string onebit = "0";
		int tmp;
		int carry = 0;

		for(int i = x.size()-1; i >= 0; i--){
			tmp = d * (x[i]-'0') + carry;
			onebit[0] = (tmp % 10) + '0';
			ret = onebit+ret;
			carry = tmp/10;
		}
		if(carry > 0){
			onebit[0] = carry + '0';
			ret = onebit+ret;
		}

		return ret;
	}

    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
		string ret = "0";
		if(num1.empty() || num2.empty() || num1 == "0" || num2 == "0")
			return "0";
		
		if(num1 == "1")
			return num2;
		if(num2 == "1")
			return num1;

		if(num1.size() < num2.size())
			swap(num1, num2);

		string pad = "";
		string tmp;
		int i;
		for(i = num2.size()-1; i >= 0; i--){
			tmp = multiply_single_digit(num1, num2[i]-'0')+pad;
			ret = add_string(ret, tmp);
			pad = pad+"0";
		}
		return ret;
    }
};
