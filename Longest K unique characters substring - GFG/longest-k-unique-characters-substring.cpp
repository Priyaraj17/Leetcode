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
        int maxLen = -1,start = 0;
        unordered_map<char, int> dict;
        for(int i = 0; i < s.size(); i++) {
            dict[s[i]]++;
            while(dict.size() > k) {
                char left = s[start];
                dict[left]--;
                if(dict[left] == 0) dict.erase(left);
                start++;
            }
            if(dict.size() == k) {
                maxLen = max(maxLen, i - start + 1);
            }
        }
        return maxLen;
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