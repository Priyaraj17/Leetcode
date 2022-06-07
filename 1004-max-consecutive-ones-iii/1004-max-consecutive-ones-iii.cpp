class Solution
{
    public:
        int longestOnes(vector<int> &nums, int k)
        {
            int countOnes = 0, maxLen = 0, start = 0;
            for (int end = 0; end < nums.size(); end++)
            {
                if (nums[end] == 1) countOnes++;
                while (end - start + 1 - countOnes > k)
                {
                    if (nums[start] == 1) countOnes--;
                    start++;
                }
                maxLen = max(maxLen, end - start + 1);
            }
            return maxLen;
        }
};