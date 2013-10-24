class Solution {
public:
    void print_letter(string &ret, string* arr, int r, int i){
		if(r == 0)
			return;
		else if(r >= 1 && r <= 3){
			for(int x = 1; x <= r; x++)
				ret += arr[i];
		}
		else if(r == 4){
			ret = ret + arr[i] + arr[i-1];
		}
		else if(r >= 5 && r < 9){
			ret += arr[i-1];
			r -= 5;
			for(int x = 1; x <= r; x++)
				ret += arr[i];
		}
		else if(r == 9){
			ret += arr[i] + arr[i-2];
		}
        else
			return;
	}

    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        
		string ret = "";
		string letter[10] = {"M", "D", "C", "L", "X", "V", "I"};
		int denominator = 1000;
		int r;
		for(int i = 0; i < 7; i += 2){
			if(num == 0)
				return ret;
			r = num/denominator;
			print_letter(ret, letter, r, i);
			num = num % denominator;
			denominator /= 10;
		}
		return ret;
    }
};