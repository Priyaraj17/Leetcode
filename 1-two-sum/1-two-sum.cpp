class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> s;
        int x;
        for(int i = 0; i < nums.size(); i++) {
            x = target - nums[i];
            if(s.find(x) != s.end()) {
                result.push_back(s[x]);
                result.push_back(i);
                break;
            }
            s[nums[i]] = i;
        }
        return result;
    }
};