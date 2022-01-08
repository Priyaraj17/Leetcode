class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        long long int ans = 0, l, b;
        while(i < j) {
            l = j - i;
            b = min(height[i], height[j]);
            ans = max(ans, l * b);
            if(height[i] < height[j]) i++;
            else j--;
        }
        return ans;
    }
};