class Solution {
public:
	string gen_next(string s){
		int size = s.size();
		int i, j;
		int cnt = 1;
		string ret = "";
		for(i = 0; i < size; ){
			cnt = 1;
			i++;
			for(j = i; j < size && s[j] == s[j-1]; j++)
				cnt++;
			ret += to_string(cnt);
			ret += s[j-1];
			i = j;
		}
		return ret;
	}

    string countAndSay(int n) {
		if(n == 1)
			return "1";
		string ret = "1";
		for(int i = 2; i <= n; i++)
			ret = gen_next(ret);
		return ret;
    }
};
