class Solution {
public:
    string intToRoman(int num) {
		string ret = "";
		vector<string> s;
		vector<int> val;
		s.push_back("I");
		s.push_back("V");
		s.push_back("X");
		s.push_back("L");
		s.push_back("C");
		s.push_back("D");
		s.push_back("M");

		val.push_back(1);
		val.push_back(5);
		val.push_back(10);
		val.push_back(50);
		val.push_back(100);
		val.push_back(500);
		val.push_back(1000);

		int i;
		int cnt;
		for(i = 6; i >= 0; i -= 2){
			if(num >= val[i]){
				cnt = num / val[i];
				num = num % val[i];
				switch(cnt){
					case 1:
					case 2:
					case 3:
						for(int x = 1; x <= cnt; x++)
							ret += s[i];
						break;
					case 4:
						ret += s[i]+s[i+1];
						break;
					case 5:
					case 6:
					case 7:
					case 8:
						ret += s[i+1];
						for(int x = 1; x <= cnt-5; x++)
							ret += s[i];
						break;
					case 9:
						ret += s[i] + s[i+2];
						break;
					default:
						break;
				}
			}
		}
		return ret;
    }
};
