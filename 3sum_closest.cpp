class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int minDiff = 1<<30;
        for (int i = 0; i < num.size(); i++)
        {
            int partialSum = target - num[i];
            int l = i + 1;
            int r = num.size() - 1;
            while(l < r)
            {
                if (abs(partialSum - num[l] - num[r]) < abs(minDiff))
                {
                    minDiff = partialSum - num[l] - num[r];
                }
                if (partialSum - num[l] - num[r] > 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return target - minDiff;
    }
};
