class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int maxSize = 0, start = 0;
        unordered_map<int, int> freq;
        for(int end = 0; end < arr.size(); end++) {
            freq[arr[end]]++;
            while(freq.size() > 2) {
                freq[arr[start]]--;
                if(!freq[arr[start]]) freq.erase(arr[start]);
                start += 1;
            }
            maxSize = max(maxSize, end - start + 1);
        }
        return maxSize;
    }
};