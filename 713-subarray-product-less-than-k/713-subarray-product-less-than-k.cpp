class Solution
{
    public:
        int numSubarrayProductLessThanK(vector<int> &nums, int k)
        {
            long long prod = 1;
            int left = 0, count = 0;
            for (int right = 0; right < nums.size(); right++)
            {
                prod *= nums[right];
                while (left < right and prod >= k)
                    prod /= nums[left++];
                if (prod < k) count += 1 + right - left;
            }
            return count;
        }
};