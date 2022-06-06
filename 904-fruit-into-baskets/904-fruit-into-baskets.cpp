class Solution
{
    public:
        int totalFruit(vector<int> &fruits)
        {
            unordered_map<int, int> freq;
            int s = 0, maxLen = 0;
            for (int e = 0; e < fruits.size(); e++)
            {
                int a = fruits[e];
                freq[a]++;
                if (freq.size() > 2)
                {
                    freq[fruits[s]] -= 1;
                    if (freq[fruits[s]] == 0) freq.erase(fruits[s]);
                    s++;
                }
                maxLen = max(maxLen, e - s + 1);
            }
            return maxLen;
        }
};