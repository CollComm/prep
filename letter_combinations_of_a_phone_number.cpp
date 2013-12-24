class Solution {
    string getDigitsMapping(char c)
    {
        switch(c)
        {
            case '0':return string(" ");
            case '1':return string("1");
            case '2':return string("abc");
            case '3':return string("def");
            case '4':return string("ghi");
            case '5':return string("jkl");
            case '6':return string("mno");
            case '7':return string("pqrs");
            case '8':return string("tuv");
            case '9':return string("wxyz");
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        answer.push_back(string(""));
        for (int i = 0; i < digits.size(); i++)
        {
            string possibleMapping = getDigitsMapping(digits[i]);
            vector<string> newAnswer;
            for (int j = 0; j < answer.size(); j++)
            {
                for (int k = 0; k < possibleMapping.length(); k++)
                {
                    string newString = answer[j];
                    newString.push_back(possibleMapping[k]);
                    newAnswer.push_back(newString);
                }
            }
            answer = newAnswer;
        }
        return answer;
    }
};
