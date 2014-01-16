class Solution {
    vector<vector<int>> answer;
    void findTarget(int l, int r, vector<int> &num, int target)
    {
        int ll = l + 1;
        int rr = r - 1;
        while(ll < rr)
        {
            if (num[ll] + num[rr] < target)
            {
                ll++;
            }
            else if (num[ll] + num[rr] > target)
            {
                rr--;
            }
            else
            {
                vector<int> v;
                v.push_back(num[l]);
                v.push_back(num[ll]);
                v.push_back(num[rr]);
                v.push_back(num[r]);
                answer.push_back(v);
                ll++;
                rr--;
                while(ll < r && num[ll] == num[ll - 1])
                {
                    ll++;
                }
                while(rr > l && num[rr] == num[rr + 1])
                {
                    rr--;
                }
            }
        }
    }
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        answer.clear();
        sort(num.begin(), num.end());
        if (num.size() < 4) return answer;
        for (int i = 0; i < num.size() - 3;)
        {
            for (int j = num.size() - 1; i < j; )
            {
                findTarget(i, j, num, target - num[i] - num[j]);
                j--;
                while(j > i && num[j] == num[j + 1])
                {
                    j--;
                }
            }
            i++;
            while(i < num.size() - 4 && num[i] == num[i - 1])
            {
                i++;
            }
        }
        return answer;
    }
};
