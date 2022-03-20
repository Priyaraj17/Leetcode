class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        start = 0
        size = 0
        maxLen = 99999
        currSum = 0
        
        for i in range(len(nums)):
            currSum += nums[i]
            while currSum >= target:
                maxLen = min(maxLen, i - start + 1);
                currSum -= nums[start];
                start += 1
        if maxLen == 99999:
            maxLen = 0
        return maxLen
                