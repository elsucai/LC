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
	
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
		if(intervals.empty())
			return ret;
		sort(intervals.begin(), intervals.end(), comp);
		ret.push_back(intervals[0]);
		for(int i = 1; i < intervals.size(); i++){
			// merge intervals[i], with last element in ret
			if(intervals[i].start > ret.back().end)
				ret.push_back(intervals[i]);
			else
				ret.back().end = max(ret.back().end, intervals[i].end);
		}
		return ret;
    }
};
