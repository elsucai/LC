class Solution {
public:
    int candy(vector<int> &ratings) {
		if(ratings.size() <= 1)
			return ratings.size();
		vector<int> c(ratings.size()+1, 0);
		int s, e, i;
		for(e = ratings.size()-1, s = e-1; s >= 0; ){
			// find non-increasing seq from right
			while(s >= 0 && ratings[s] <= ratings[s+1])
				s--;
			s++;
			// assign candy
			c[s] = 1;
			for(i = s+1; i <= e; i++){
				if(ratings[i] == ratings[i-1])
					c[i] = 1;
				else
					c[i] = c[i-1]+1;
			}
			if(c[e] <= c[e+1])
				c[e] = c[e+1]+1;
			e = s-1;
			s = e-1;
		}
		// s < 0
		if(e == 0){
			c[e] = 1 + c[e+1];
		}
		s = 0;
		for(i = 0 ; i < ratings.size(); i++)
			s += c[i];
		return s;
    }
};
