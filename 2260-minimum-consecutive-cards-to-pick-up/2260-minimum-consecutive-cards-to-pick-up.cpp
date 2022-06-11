class Solution
{
    public:
        int minimumCardPickup(vector<int> &cards)
        {
            unordered_map<int, int> freq;
            int minLen = 1e9, winStart = 0;
            for (int winEnd = 0; winEnd < cards.size(); winEnd++)
            {
                int num = cards[winEnd];
                freq[num]++;
                while (freq[num] == 2)
                {
                    minLen = min(minLen, winEnd - winStart + 1);
                    int start = cards[winStart++];
                    freq[start]--;
                }
            }
            return minLen == 1e9 ? -1 : minLen;
        }
};