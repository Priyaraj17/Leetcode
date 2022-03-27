class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int start = 0, maxLen = 0, maxCount = 0;
        for(int end = 0; end < s.size(); end++) {
            char ch = s[end];
            freq[ch]++;
            maxCount = max(maxCount, freq[ch]);
            while(end - start + 1 - maxCount > k) {
                char left = s[start];
                freq[left]--;
                start++;
            }
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};