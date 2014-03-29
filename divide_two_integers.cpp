class Solution {
public:
	    int divide(int dividend, int divisor) {
	    long long dividend_L = dividend;
	    long long divisor_L = divisor;
        bool positive = 1;
        if (dividend_L < 0 && divisor_L > 0) {
            dividend_L = -dividend_L;
            positive = 0;
        }
        if (dividend_L > 0 && divisor_L < 0) {
            divisor_L = -divisor_L;
            positive = 0;
        }
        if (dividend_L < 0 && divisor_L < 0) {
            divisor_L = -divisor_L;
            dividend_L = -dividend_L;
        }
        if (divisor_L == 1 && positive) return dividend_L;
        if (divisor_L == 1 && !positive) return -dividend_L;
        if (divisor_L > dividend_L) return 0;
        long long left = dividend_L;
        int result = 0;
        long long extDivisor = divisor_L;
		int numInc = 0;
		while(extDivisor < left) {
                extDivisor <<= 1;
                numInc++;
        }
		extDivisor >>= 1;
		if (numInc > 0)
		    numInc--;
        while (left >= divisor_L) {
			result += (int)(1 << numInc);
            left -= extDivisor;
			while(extDivisor > left) {
				extDivisor >>= 1;
				if (numInc > 0)
				    numInc--;
			}
        }
        if (!positive) {
            result = -result;
        }
        return result;
    }
};
