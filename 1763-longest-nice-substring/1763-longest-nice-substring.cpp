class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size() < 2) return "";
        unordered_set<char> st;
        for(auto i : s) st.insert(i);
        for(int i = 0; i < s.size(); i++) {
            if(st.count(tolower(s[i])) and st.count(toupper(s[i]))) continue;
            string prev = longestNiceSubstring(s.substr(0, i));
            string nex = longestNiceSubstring(s.substr(i + 1));
            return prev.size() >= nex.size() ? prev : nex;
        }
        return s;
    }
};