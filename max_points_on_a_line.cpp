/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
    vector<Point> newPoints;
    vector<double> slope;
    vector<Point> peri;
public:
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (points.size() <= 2)
        {
            return points.size();
        }
        int maxPAll = 2;
        for (int i = 0; i < points.size(); i++)
        {
            newPoints.clear();
            slope.clear();
            peri.clear();
            for (int j = 0; j < points.size(); j++)
            {
                newPoints.push_back(Point(points[j].x - points[i].x, points[j].y - points[i].y));
                if (newPoints[newPoints.size() - 1].x != 0)
                {
                    slope.push_back((double)newPoints[newPoints.size() - 1].y / newPoints[newPoints.size() - 1].x);
                }
                else
                {
                    peri.push_back(newPoints[(int)newPoints.size() - 1]);
                }
            }
            int countBase = 0;
            for (int j = 0; j < peri.size(); j++)
            {
                if (peri[j].x == 0 && peri[j].y == 0)
                {
                    countBase++;
                }
            }
            if (slope.size() > 1)
            {
                sort(slope.begin(), slope.end());
                countBase++;
            }
            // count
            int maxPtmp = max(1, (int)peri.size());
            int contingentP = countBase;
            for (int j = 0; j < (int)slope.size() - 1; j++)
            {
                if (fabs(slope[j+1] - slope[j]) < 1e-6)
                {
                    contingentP++;
                }
                else
                {
                    if (contingentP > maxPtmp)
                    {
                        maxPtmp = contingentP;
                    }
                    contingentP = countBase;
                }
            }
            if (contingentP > maxPtmp)
            {
                maxPtmp = contingentP;
            }
            if (maxPtmp > maxPAll)
            {
                maxPAll = maxPtmp;
            }
        }
        return maxPAll;
    }
};
