class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, count = 0;
        unordered_map<char, int> dict;
        int i = 0, j = 0;
        while(j < s.size()) {
            char ch = s[j];
            if(dict.count(ch) and dict[ch] >= i) {
                i = dict[ch] + 1;
                count = j - i;
            }
            dict[ch] = j;
            count++;
            j++;
            maxLen = max(maxLen, count);
        }
        return maxLen;
    }
};