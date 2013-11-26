#include<cstring>
using namespace std;
class Solution {
public:
    bool isNumber(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int length = strlen(s);
        char* filteredS = new char[length];
        // check if there is alphabet characters
        int numP = 0, numE = 0, numM = 0, numPlus = 0, numN = 0;
        int posP = -1, posE = -1, posM = -1;
        int posPlus[2] = {-1, -1};
        
        // Remove pre and suffix empty space
		int totalLen = 0;
		int i = 0;
		
		for(; i < length;)
		{
			if (s[i] == ' ')
			{
				i++;
			}
			else
			{
			    break;
			}
		}
        for(; i < length; i++)
        {
            if (s[i] != ' ')
            {
				filteredS[totalLen] = s[i];
				totalLen++;
			}
			else
			{
			    break;
			}
        }
        for(; i < length; i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if (i < length)
        {
            delete filteredS;
            return false;
        }
		filteredS[totalLen] = 0;
		for(int i = 0; i < totalLen; i++)
		{
			if (!(filteredS[i] == '+' || filteredS[i] == '-' || filteredS[i] == '.' || filteredS[i] == 'e' || (filteredS[i]<='9' && filteredS[i]>='0')))
			{
				//White list
				delete filteredS;
				return false;
			}
			else
			{
				if (filteredS[i] == '.')
				{
					numP++;
					posP = i;
				}
				if (filteredS[i] == 'e')
				{
					numE++;
					posE = i;
				}
				if (filteredS[i] == '-')
				{
				    numM++;
				    posM = i;
				}
				if (filteredS[i] == '+')
				{
				    if (numPlus < 2)
				    {
				        posPlus[numPlus] = i;
				    }
				    numPlus++;
				}
				if (filteredS[i] >= '0' && filteredS[i] <= '9')
				{
				    numN++;
				}
			}
		}
		if (numE>1 || numP>1 || numM > 1 || numPlus > 2 || numN==0 || posE==totalLen - 1 || (numE == 1 && numP == 1 && posE-posP <=1 && posP==0) || (numE==1 && numP==1 && posE-posP <=1 && posP == totalLen - 1) || (numE==1 && ((posE + 1)>= totalLen || (posE-1) < 0)) || (numP == 1 && totalLen==1) || (numM==1 && numE == 0 && posM != 0) || (numM == 1 && numE == 1 && !(posM == 0 || posM-posE==1)) || (numM == 1 && (posM+1>=totalLen || (posM+1<totalLen && !((filteredS[posM+1]<='9' && filteredS[posM+1]>='0') || (filteredS[posM+1]=='.'))))) || (numPlus == 1 && !(posPlus[0] == 0 || (numE == 1 && posPlus[0] == posE + 1 && posPlus[0]!=totalLen-1))) || (numPlus == 2 && !(posPlus[0] == 0 && posPlus[1] == posE + 1)) || (numE == 1 && numP ==1 && posP>posE) || (numE==1 && numM ==1 && posE==posM+1) )
		{
		    delete filteredS;
            return false;
		}
		return true;
    }
};
