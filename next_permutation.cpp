class Solution {
public:
    void nextPermutation(vector<int> &num) {
        bool isLargest = true;
        int pos = 0;
        int target = 0;
        for (int i = 0; i < num.size() - 1; i++)
        {
            if (num[i] < num[i + 1])
            {
                isLargest = false;
                pos = i;
            }
        }
        if (isLargest)
        {
            // output lowest
            sort(num.begin(), num.end());
        }
        else
        {
            for (int i = pos + 1; i < num.size(); i++)
            {
                if (num[i] > num[pos])
                {
                    target = i;
                }
            }
            swap(num[pos], num[target]);
            for (int i = pos + 1, j = 1; i < (num.size() + pos + 1)/2; i++, j++)
            {
                swap(num[i], num[num.size() - j]);
            }
        }
    }
};
