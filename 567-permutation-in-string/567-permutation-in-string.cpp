class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char, int> freq;
        for(auto i : s1) freq[i]++;
        int start = 0, matched = 0;
        
        for(int end = 0; end < s2.size(); end++) {
            char ch = s2[end];
            if(freq.find(ch) != freq.end()) {
                freq[ch]--;
                if(freq[ch] == 0) 
                    matched++;
            }
            
            if(matched == freq.size()) return true;
            
            if(end >= s1.size() - 1) {
                char left = s2[start++];
                if(freq.find(left) != freq.end()) {
                    if (freq[left] == 0) matched--;
                    freq[left]++;
                }
            }
        }
        return false;
    }
};