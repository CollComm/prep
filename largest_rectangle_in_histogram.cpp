class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> asc;
        int maxArea = 0;
        height.push_back(0);
        for (int i = 0; i < height.size();)
        {
            if (asc.empty() || height[i] >= height[asc.top()])
            {
                asc.push(i);
                i++;
            }
            else
            {
                int currIndex = asc.top();
                asc.pop();
                maxArea = max(maxArea, height[currIndex] * (asc.empty()? i : i - 1 - asc.top()));
            }
        }
        height.pop_back();
        return maxArea;
    }
};
