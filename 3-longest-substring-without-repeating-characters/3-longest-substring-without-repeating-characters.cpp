class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, maxLen = 0;
        unordered_map<char, int> freq;
        for(end = 0; end < s.size(); end++) {
            char ch = s[end];
            if(freq.find(ch) != freq.end()) {
                start = max(start, freq[ch] + 1);
            }
            freq[ch] = end;
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};