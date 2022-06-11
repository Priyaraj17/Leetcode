class Solution
{
    public:
        string minWindow(string s, string t)
        {
            if (s.size() < t.size() or s == ""
                or t == "") return "";
            unordered_map<char, int> freq;

            for (auto i: t) freq[i]++;

            int winS = 0, minLen = 1e9, matched = 0, start = 0;

            for (int winE = 0; winE < s.size(); winE++)
            {
                char rightChar = s[winE];
                if (freq.find(rightChar) != freq.end())
                {
                    freq[rightChar]--;
                    if (freq[rightChar] >= 0) matched++;
                }
                while (matched == t.size())
                {
                    if (minLen > winE - winS + 1)
                    {
                        minLen = winE - winS + 1;
                        start = winS;
                    }
                    char rightChar = s[winS++];
                    if (freq.find(rightChar) != freq.end())
                    {
                        freq[rightChar]++;
                        if (freq[rightChar] == 1) matched--;
                    }
                }
            }
            return minLen == 1e9 ? "" : s.substr(start, minLen);
        }
};