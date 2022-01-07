class Solution {
public:
    int maxSumLen(vector<int> &arr, int right, int size, int n) {
        int currentSum = 0, maxSum = 0;
        int left = right;
        while(right < n) {
            currentSum += arr[right];
            if(right - left + 1 > size) {
                currentSum -= arr[left++];
            }
            maxSum = max(maxSum, currentSum);
            right++;
        }
        return maxSum;
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int prefixSum = 0, i = 0, ans = 0;
        for(int j = 0; j < nums.size(); j++) {
            prefixSum += nums[j];
            if(j - i + 1 > firstLen) {
                prefixSum -= nums[i++];
            }
            int secSumNext = maxSumLen(nums, j + 1, secondLen, nums.size());
            int secSumPrev = 0;
            if(i > secondLen - 1) secSumPrev = maxSumLen(nums, 0, secondLen, i);
            int totalCurrent = prefixSum + max(secSumNext, secSumPrev);
            ans = max(ans, totalCurrent);
        }
        return ans;
    }
};