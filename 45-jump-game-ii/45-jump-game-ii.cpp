class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;
        
        for(int i = n - 2; i >= 0; i--) {
            int jump = INT_MAX;
            for(int j = i + 1; j <= min(nums[i] + i, n - 1); j++)
                jump = min(jump, dp[j]);
            if(jump != INT_MAX) dp[i] = jump + 1;
        }
        return dp[0];
    }
};