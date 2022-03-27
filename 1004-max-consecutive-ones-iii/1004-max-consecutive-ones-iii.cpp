class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0, start = 0, maxOnes = 0;
        for(int end = 0; end < nums.size(); end++) {
            if(nums[end] == 1) maxOnes++;
            while(end - start + 1 - maxOnes > k) {
                if(nums[start] == 1) maxOnes--;
                start++;
            }
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};