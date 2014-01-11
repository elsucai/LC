class Solution {
public:
    string intToRoman(int num) {
		vector<int> values;
		vector<string> symbols;
		values.push_back(1);
		values.push_back(5);
		values.push_back(10);
		values.push_back(50);
		values.push_back(100);
		values.push_back(500);
		values.push_back(1000);
		symbols.push_back("I");
		symbols.push_back("V");
		symbols.push_back("X");
		symbols.push_back("L");
		symbols.push_back("C");
		symbols.push_back("D");
		symbols.push_back("M");

		int remain;
		string ret = "";
		for(int i = 6; i >= 0; i -= 2){
			if(num == 0)
				return ret;
			if(num < values[i])
				continue;
			remain = num%values[i];
			num /= values[i];
			switch(num){
				case 1:
				case 2:
				case 3:
					for(int x = 1; x <= num; x++)
						ret += symbols[i];
					break;
				case 4:
					ret += symbols[i]+symbols[i+1];
					break;
				case 5:
				case 6:
				case 7:
				case 8:
					ret += symbols[i+1];
					for(int x = 1; x <= num-5; x++)
						ret += symbols[i];
					break;
				case 9:
					ret += symbols[i]+symbols[i+2];
					break;
				default:
					break;
			}
			num = remain;
		}
    }
};
