class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int start = 0, maxLen = 0;
            unordered_map<char, int> freq;
            for (int e = 0; e < s.size(); e++)
            {
                char ch = s[e];
                freq[ch]++;
                while (start < e and freq[ch] > 1)
                {
                    freq[s[start]]--;
                    start++;
                }
                maxLen = max(maxLen, e - start + 1);
            }
            return maxLen;
        }
};