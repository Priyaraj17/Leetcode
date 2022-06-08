class Solution
{
    public:
        vector<int> findAnagrams(string s, string p)
        {
            int winStart = 0, matched = 0;
            unordered_map<char, int> freq;
            vector<int> res;
            for (auto i: p) freq[i]++;
            for (int winEnd = 0; winEnd < s.size(); winEnd++)
            {
                char rightChar = s[winEnd];
                if (freq.find(rightChar) != freq.end())
                {
                    freq[rightChar]--;
                    if (!freq[rightChar]) matched++;
                }
                if (matched == freq.size())
                {
                    res.push_back(winStart);
                }
                if (winEnd >= p.size() - 1)
                {
                    char leftChar = s[winStart++];
                    if (freq.find(leftChar) != freq.end())
                    {
                        if (!freq[leftChar]) matched--;
                        freq[leftChar]++;
                    }
                }
            }
            return res;
        }
};