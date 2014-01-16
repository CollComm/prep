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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> answer;
        int minStart = newInterval.start;
        int maxEnd = newInterval.end;
        bool inserted = false;
        for (int i = 0; i < intervals.size(); i++)
        {
            if (newInterval.start > intervals[i].end)
            {
                answer.push_back(intervals[i]);
            }
            else
            {
                if (newInterval.start < intervals[i].start)
                {
                    if (newInterval.end > intervals[i].end)
                    {
                        continue;
                    }
                    else if (newInterval.end < intervals[i].start)
                    {
                        if (!inserted)
                        {
                        answer.push_back(Interval(minStart, maxEnd));
                        inserted = true;
                        }
                        answer.push_back(intervals[i]);
                    }
                    else
                    {
                        maxEnd = max(maxEnd, intervals[i].end);
                    }
                }
                else
                {
                    minStart = min(minStart, intervals[i].start);
                    maxEnd = max(maxEnd, intervals[i].end);
                }
            }
        }
        if (!inserted)
        {
            answer.push_back(Interval(minStart, maxEnd));
        }
        return answer;
    }
};
