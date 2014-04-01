class Solution {
	public:
		string single_digit(string &a, int as, int ae, char d){
			int x = d-'0';
			if(x == 0)
				return "0";
			if(x == 1)
				return a.substr(as, ae-as+1);
			int carry = 0;
			int prod = 0;
			int i;
			string ret = "";
			for(i = ae; i >= as; i--){
				prod = carry+x*(a[i]-'0');
				carry = prod / 10;
				prod = prod % 10;
				ret = char(prod+'0')+ret;
			}
			if(carry > 0)
				ret = char(carry+'0')+ret;
			return ret;
		}

		string add(string &a, string &b){
			string ret = "";
			int i, j;
			int carry = 0;
			int sum = 0;
			for(i = a.size()-1, j = b.size()-1; i >= 0 && j >= 0; i--, j--){
				sum = a[i]-'0'+b[j]-'0'+carry;
				carry = sum / 10;
				sum = sum % 10;
				ret = char(sum+'0')+ret;
			}
			for(; i >= 0; i--){
				sum = a[i]-'0'+carry;
				carry = sum / 10;
				sum = sum % 10;
				ret = char(sum+'0')+ret;
			}
			for(; j >= 0; j--){
				sum = b[j]-'0'+carry;
				carry = sum / 10;
				sum = sum % 10;
				ret = char(sum+'0')+ret;
			}
			if(carry > 0)
				ret = char(carry+'0')+ret;
			return ret;
		}

		string helper(string &a, int as, int ae, string &b, int bs, int be){
			if(bs > be){
				return ""; 
			}
			string single = single_digit(a, as, ae, b[be]);
			if(bs == be)
				return single;
			string ret = helper(a, as, ae, b, bs, be-1);
			ret += "0";
			return add(single, ret);
		}

		string multiply(string num1, string num2) {
			if(num1.size() < num2.size())
				swap(num1, num2);
			return helper(num1, 0, num1.size()-1, num2, 0, num2.size()-1);
		}
};
