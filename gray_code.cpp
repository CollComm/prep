#include<set>
using namespace std;
class Solution {
    set<int> existed;
public:
    int changeBit(int num, int pos)
    {
        return ((num&(1<<pos))==0)?(num|(1<<pos)):(num&(~(1<<pos)));
    }
    vector<int> grayCode(int n) {
        existed.clear();
        vector<int> answer;
        answer.push_back(0);
        if (n==0)
        {
            return answer;
        }
        int startNumber(0);
        int totalNumber = 0;
        existed.insert(0);
        while(totalNumber< (1<<(n)))
        {
            int tmpNumber, i;
            for (i = 0; i < n; i++)
            {
                tmpNumber = changeBit(startNumber, i);
                auto it = existed.find(tmpNumber);
                if (it == existed.end())
                {
                    break;
                }
            }
            if (i >= n)
            {
                break;
            }
            existed.insert(tmpNumber);
            startNumber = tmpNumber;
            answer.push_back(startNumber);
            totalNumber++;
        }
        return answer;
    }
};
