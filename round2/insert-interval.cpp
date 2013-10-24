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
    int find_closest_index(vector<Interval> &intervals, int s, int e, int val){
		int m;
		
		while(s <= e){
			m = s + (e - s)/2;
			if(intervals[m].start == val)
				return m;
			if(intervals[m].start < val)
				s = m+1;
			else
				e = m-1;
		}
		
		if(e == -1)
			return 0;
		return e;
	}
	
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<Interval> ret;
		int size = intervals.size();
		
		if(intervals.empty()){
			ret.push_back(newInterval);
			return ret;
		}
		
		// handle head and tail
		if(newInterval.end < intervals[0].start){
			ret.push_back(newInterval);
			for(int i = 0; i < size; i++)
				ret.push_back(intervals[i]);
			return ret;
		}
		if(newInterval.start > intervals[size-1].end){
			for(int i = 0; i < size; i++)
				ret.push_back(intervals[i]);
			ret.push_back(newInterval);
			return ret;
		}
		
		int new_s, new_e, a, b, s, e;
		s = newInterval.start;
		e = newInterval.end;
		a = find_closest_index(intervals, 0, size-1, s);
		b = find_closest_index(intervals, 0, size-1, e);
		
		if(s <= intervals[a].end){
			new_s = min(s, intervals[a].start);
		}
		else{
			a++;
			new_s = s;
		}
		
		new_e = max(e, intervals[b].end);
		
		for(int i = 0; i < a; i++)
			ret.push_back(intervals[i]);
			
		newInterval.start = new_s;
		newInterval.end = new_e;
		ret.push_back(newInterval);
		
		for(int i = b+1; i < size; i++)
			ret.push_back(intervals[i]);
			
		return ret;
    }
};