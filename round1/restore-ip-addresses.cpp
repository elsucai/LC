class Solution {
public:
	vector<string> helper(string str, int s, int e, int parts, bool &valid){
		vector<string> ret;
		vector<string> tmp;
		bool flag = false;
		
		if(s > e){
			if(parts == 0)
				valid = true;
			else
				valid = false;
			return ret;
		}
		
		// s <= e
		if(parts <= 0){
			valid = false;
			return ret;
		}
			
		int digits = e - s + 1;
		if (!(digits <= 3*parts && digits >= parts)){
			valid = false;
			return ret;
		}
			
		string sub;
		//case 1: take 1 digit
		sub = str.substr(s, 1);
		
		tmp = helper(str, s+1, e, parts - 1, valid);
		if(valid){
			flag = true;
			if(tmp.empty())
				ret.push_back(sub);
			else{
				for(int i = 0; i < tmp.size(); i++){
					ret.push_back(sub+"."+tmp[i]);
				}
			}
		}
		
		// case 2: take 2 digits
		
		if(e - s >= 1){
			sub = str.substr(s, 2);
			if(str[s] >= '1'){		
				tmp = helper(str, s+2, e, parts - 1, valid);
				if(valid){
					flag = true;
					if(tmp.empty())
						ret.push_back(sub);
					else{
						for(int i = 0; i < tmp.size(); i++){
							ret.push_back(sub+"."+tmp[i]);
						}
					}
				}
			}
		}
		
		// case 3: take 3 digits
		if(e - s >= 2){
			sub = str.substr(s, 3);
			if(str[s] == '1' || (str[s] == '2' && (str[s+1] <= '4' || (str[s+1] == '5' && str[s+2] <= '5')))){
				tmp = helper(str, s+3, e, parts - 1, valid);
				if(valid){
					flag = true;
					if(tmp.empty())
						ret.push_back(sub);
					else{
						for(int i = 0; i < tmp.size(); i++){
							ret.push_back(sub+"."+tmp[i]);
						}
					}
				}
			}	
		}
		
		valid = flag;
		return ret;
	}
	
	
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
		if(s.empty())
			return ret;
		bool valid = false;
		return helper(s, 0, s.size()-1, 4, valid);
    }
};