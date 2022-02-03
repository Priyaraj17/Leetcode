class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        int high = INT_MIN;
        for(auto i : nums) {
            s.insert(i);
            high = max(high, i);
        }
        if(high < 0)
            return 1;
        for(int i = 1; i <= high; i++) {
            if(s.find(i) == s.end())
                return i;
        }
        return high + 1;
    }
};