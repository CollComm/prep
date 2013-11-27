#include<algorithm>
using namespace std;
class Solution {
public:
int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int totalNumber=0;
        bool neg = false;
		sort(A, A+n);
        for (int i = 0; i < n; i++)
        {
            if (neg)
            {
                totalNumber = totalNumber - A[i];
                neg = false;
            }
            else
            {
                totalNumber = totalNumber + A[i];
                neg = true;
            }
        }
        return totalNumber;
    }
};
