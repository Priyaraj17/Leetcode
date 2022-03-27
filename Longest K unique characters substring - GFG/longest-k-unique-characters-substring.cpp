// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int maxLen = 0, start = 0;
        unordered_map<char, int> freq;
        for(int end = 0; end < s.size(); end++) {
            char ch = s[end];
            freq[ch]++;
            while(freq.size() > k) {
                freq[s[start]]--;
                if(freq[s[start]] == 0) freq.erase(s[start]);
                start++;
            }
            if(freq.size() == k)
                maxLen = max(maxLen, end - start + 1);
        }
        return maxLen == 0 ? -1 : maxLen;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends