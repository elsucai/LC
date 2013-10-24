/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	static bool comp(Interval a, Interval b){
		return a.start < b.start;
	}
	
	void insert(vector<Interval> &ret, Interval n){
		if(ret.empty())
			ret.push_back(n);
		
		Interval cur = ret[ret.size()-1];
		if(n.start > cur.end){
			ret.push_back(n);
			return;
		}
		
		// n.start <= cur.end && n.start >= cur.start
		cur.end = max(cur.end, n.end);
		ret[ret.size()-1].end = cur.end;
	}
	
	
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<Interval> ret;
        
        sort(intervals.begin(), intervals.end(), comp);
        
        for(int i = 0; i < intervals.size(); i++){
        	insert(ret, intervals[i]);
        }
        
        return ret;
    }
};
