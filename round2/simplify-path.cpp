class Solution {
	public:
		string simplifyPath(string path) {
			// IMPORTANT: Please reset any member data you declared, as
			// the same Solution instance will be reused for each test case.
			stack<string> s;
			string token;
			if(path.empty())
				return path;
			if(path[0] == '/'){
				s.push("/");
				path = path.substr(1, path.size()-1);
			}
			stringstream ss(path);
			while(getline(ss, token, '/')){
				if(token == ".")
					continue;
				else if(token == ".."){
					if(s.empty() || s.top() == "..")
						s.push("..");
					else if(s.top() == "/")
						continue;
					else
						s.pop();
				}
				else if(!token.empty()){
					// names
					s.push(token);
				}
				else
				    ;
			}
			string ret = "";
			while(!s.empty()){
				ret = s.top()+"/"+ret;
				s.pop();
			}
			if(!ret.empty())
			    ret = ret.substr(0, ret.size()-1);
			if(ret.size() >= 2 && ret[1] == '/')
				ret = ret.substr(1, ret.size()-1);
			return ret;
		}
};
