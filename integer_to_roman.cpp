class Solution {
    string getRomanChar(int& num)
    {
        string tmpChars;
        // Here the return cannot be removed otherwise, the running sequence would be changed.
        if (num >= 1000)
        {
            num -= 1000;
            tmpChars.push_back('M');
            return tmpChars;
        }
        else if (num >= 900)
        {
            num -= 900;
            tmpChars.push_back('C');
            tmpChars.push_back('M');
            return tmpChars;
        }
        else if (num >= 500)
        {
            num -= 500;
            tmpChars.push_back('D');
            return tmpChars;
        }
        else if (num >= 400)
        {
            num -= 400;
            tmpChars.push_back('C');
            tmpChars.push_back('D');
            return tmpChars;
        }
        else if (num >= 100)
        {
            num -= 100;
            tmpChars.push_back('C');
            return tmpChars;
        }
        else if (num >= 90)
        {
            num -= 90;
            tmpChars.push_back('X');
            tmpChars.push_back('C');
            return tmpChars;
        }
        else if (num >= 50)
        {
            num -= 50;
            tmpChars.push_back('L');
            return tmpChars;
        }
        else if (num >= 40)
        {
            num -= 40;
            tmpChars.push_back('X');
            tmpChars.push_back('L');
            return tmpChars;
        }
        else if (num >= 10)
        {
            num -= 10;
            tmpChars.push_back('X');
            return tmpChars;
        }
        else if (num >= 9)
        {
            num -= 9;
            tmpChars.push_back('I');
            tmpChars.push_back('X');
            return tmpChars;
        }
        else if (num >= 5)
        {
            num -= 5;
            tmpChars.push_back('V');
            return tmpChars;
        }
        else if (num >= 4)
        {
            num -= 4;
            tmpChars.push_back('I');
            tmpChars.push_back('V');
            return tmpChars;
        }
        else
        {
            num -= 1;
            tmpChars.push_back('I');
            return tmpChars;
        }
    }
public:
    string intToRoman(int num) {
        int currNumber = num;
        string answer;
        while (currNumber > 0)
        {
            answer.append(getRomanChar(currNumber));
        }
        return answer;
    }
};
