class Solution
{
    public:
        int threeSumClosest(vector<int> &arr, int target)
        {
            int n = arr.size();
            sort(arr.begin(), arr.end());
            int ans = INT_MAX, sum, diff, minDiff = INT_MAX;
            for (int s = 0; s < n - 2; s++)
            {
                int i = s + 1, j = n - 1;
                while (i < j)
                {
                    sum = arr[s] + arr[i] + arr[j];
                    diff = target - sum;
                    if (diff == 0) return sum;
                    if (abs(diff) < abs(minDiff))
                    {
                        minDiff = diff;
                        ans = sum;
                    }
                    if (sum < target) i++;
                    else j--;
                }
            }
            return ans;
        }
};