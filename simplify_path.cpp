class Solution {
    void cleanZeroLengthElements(stack<string>& elems)
    {
        while (!elems.empty() && ((elems.top().compare(".") == 0) || (elems.top().length() == 0)))
            {
                elems.pop();
            }
    }
public:
    string simplifyPath(string path) {
        stack<string> elems;
        int lastPos = 0;
        for (int i = 1; i < path.length(); i++)
        {
            if (path[i] == '/')
            {
                elems.push(path.substr(lastPos + 1, i - 1 - lastPos));
                lastPos = i;
            }
        }
        if (path[path.length() - 1] != '/')
        {
            elems.push(path.substr(lastPos + 1, path.length() - 1 - lastPos));
        }
        vector<string> validString;
        string ans;
        int removePrev = 0;
        while(!elems.empty())
        {
            cleanZeroLengthElements(elems);
            if (!elems.empty() && (elems.top().compare("..")) != 0 && removePrev > 0)
            {
                elems.pop();
                removePrev--;
            }
            while (!elems.empty() && (elems.top().compare("..") == 0))
            {
                elems.pop();
                removePrev++;
            }
            cleanZeroLengthElements(elems);
            if (!elems.empty() && (elems.top().compare("..") != 0) && removePrev == 0)
            {
                validString.push_back(elems.top());
                elems.pop();
            }
        }
        for (int i = validString.size() - 1; i >= 0; i--)
        {
            ans.push_back('/');
            ans.append(validString[i]);
        }
        if (ans.length() == 0)
        {
            ans.push_back('/');
        }
        return ans;
    }
};
