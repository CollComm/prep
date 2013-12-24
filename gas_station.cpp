class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> offset;
        int tank = 0;
        int pos = 0;
        int cnt = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            offset.push_back(gas[i] - cost[i]);
        }
        for (int i = 0; i < gas.size(); i++)
        {
            offset.push_back(gas[i] - cost[i]);
        }
        for (int i = 0; i < offset.size(); i++)
        {
            if (tank < 0)
            {
                tank = offset[i];
                if (tank < 0)
                {
                    cnt = 0;
                }
                else
                {
                    cnt = 1;
                }
                pos = i;
            }
            else
            {
                tank += offset[i];
                cnt++;
            }
        }
        if (cnt < gas.size())
        {
            return -1;
        }
        else
        {
            return pos;
        }
    }
};
