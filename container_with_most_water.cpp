using namespace std;
#include<algorithm>
class Solution {
public:
    int maxArea(vector<int> &height) {
        int start = 0;
        int end = height.size() - 1;
        int maxContainer = 0;
        while(start < end)
        {
            int tmpArea = 0;
            if (height[start] < height[end])
            {
                tmpArea = height[start] * (end - start);
                start++;
            }
            else
            {
                tmpArea = height[end] * (end - start);
                end--;
            }
            maxContainer = max(tmpArea, maxContainer);
        }
        return maxContainer;
    }
};
