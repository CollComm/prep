/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compInterval(const Interval&a, const Interval&b)
    {
        return (a.start < b.start);
    }
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), compInterval);
        vector<Interval> answer;
        if (intervals.size() == 0) return answer;
        int maxEnd = intervals[0].end;
        int minStart = intervals[0].start;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (maxEnd >= intervals[i].start)
            {
                maxEnd = max(maxEnd, intervals[i].end);
            }
            else
            {
                answer.push_back(Interval(minStart, maxEnd));
                minStart = intervals[i].start;
                maxEnd = intervals[i].end;
            }
        }
        answer.push_back(Interval(minStart, maxEnd));
        return answer;
    }
};
