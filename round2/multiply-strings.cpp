class Solution {
public:

	string single_multi(vector<string> &cache, string x, int d){
		if(cache[d] != "")
			return cache[d];
		string onebit = "0";
		int carry = 0;
		int p = 0;
		string ret = "";
		int i = x.size()-1;
		for(; i >= 0; i--){
			p = d *(x[i] - '0') + carry;
			carry = p/10;
			p = p%10;
			
			onebit[0] = '0'+p;
			ret = onebit+ret;
		}
		if(carry > 0){
			onebit[0] = '0'+carry;
			ret = onebit + ret;
		}
		cache[d] = ret;
		return ret;
	}

	string add(string x, string y){
		int carry = 0;
		int i = x.size()-1;
		int j = y.size()-1;
		int sum;
		string onebit = "0";
		string ret = "";
		for(; i >= 0 && j >= 0; i--, j--){
			sum = x[i] - '0' + y[j] - '0' + carry;
			carry = sum/10;
			sum = sum%10;
			onebit[0] = '0' + sum;
			ret = onebit+ret;
		}
	
		if(j >= 0){
			i = j;
			swap(x, y);
		}
		for(; i >= 0; i--){
			sum = x[i] - '0' + carry;
			carry = sum/10;
			sum = sum%10;
			onebit[0] = '0'+sum;
			ret = onebit+ret;
		}
		if(carry > 0){
			onebit[0] = '0'+carry;
			ret = onebit + ret;
		}
		return ret;
	}

    string multiply(string num1, string num2) {
		if(num1 == "0" || num2 == "0")
			return "0";
		if(num1 == "1")
			return num2;
		if(num2 =="1")
			return num1;

		if(num1.size() < num2.size())
			swap(num1, num2);

		//num2 is shorter
		vector<string> cache(10, "");
		cache[0] = "0";
		cache[1] = num1;

		string sum = "0";
		string tmp, pad;
		pad = tmp = "";
		int i;
		for(i = num2.size()-1; i >= 0; i--){
			tmp = single_multi(cache, num1, num2[i]-'0');
			if(tmp != "0"){
				tmp += pad;
			}
			sum = add(sum, tmp);
			pad += "0";
		}
		return sum;
    }
};
