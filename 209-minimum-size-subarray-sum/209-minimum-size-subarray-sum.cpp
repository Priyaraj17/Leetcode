class Solution
{
    public:
        int minSubArrayLen(int target, vector<int> &nums)
        {
            int currSum = 0, minLen = 1e9, s = 0;
            for (int e = 0; e < nums.size(); e++)
            {
                currSum += nums[e];
                while (currSum >= target)
                {
                    minLen = min(minLen, e - s + 1);
                    currSum -= nums[s++];
                }
            }
            return minLen == 1e9 ? 0 : minLen;
        }
};