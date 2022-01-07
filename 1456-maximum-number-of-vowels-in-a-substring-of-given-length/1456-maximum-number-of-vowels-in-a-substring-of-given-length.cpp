class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
    }
    
    int maxVowels(string s, int k) {
        int count = 0, maxCount = 0;
        int maxLen = 0, i = 0;
        for(int j = 0; j < s.size(); j++) {
            char c = s[j];
            count += isVowel(c);
            if(j > k - 1) {
                c = s[i];
                count -= isVowel(c);
                i++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};