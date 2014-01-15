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
	int find_first_start_no_greater_than_x(vector<Interval> &intervals, int x){
		int s, e, m, val;
		for(s = 0, e = intervals.size()-1; s <= e; ){
			m = s + (e-s)/2;
			val = intervals[m].start;
			if(val = x)
				return m;
			if(val > x){
				e = m-1;
			}
			else{
				s = m+1;
			}
		}
		return e;
	}
    
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> ret;
		int i, j;
		// handle special cases;
		if(intervals.empty()){
			ret.push_back(newInterval);
			return ret;
		}
		if(newInterval.end < intervals[0].start){
			ret = intervals;
			ret.insert(ret.begin(), newInterval);
			return ret;
		}
		if(newInterval.start > intervals[intervals.size()-1].end){
			ret = intervals;
			ret.push_back(newInterval);
			return ret;
		}

		// merge
		i = find_first_start_no_greater_than_x(intervals, newInterval.start);
		j = find_first_start_no_greater_than_x(intervals, newInterval.end);

		if(i == -1)
			i = 0;
		if(newInterval.start > intervals[i].end)
			i++;
		newInterval.start = min(intervals[i].start, newInterval.start);
		newInterval.end = max(intervals[j].end, newInterval.end);
		int x;
		for(x = 0; x < i; x++)
			ret.push_back(intervals[x]);
		ret.push_back(newInterval);
		for(x = j+1; x < intervals.size(); x++)
			ret.push_back(intervals[x]);
		return ret;
    }
};
