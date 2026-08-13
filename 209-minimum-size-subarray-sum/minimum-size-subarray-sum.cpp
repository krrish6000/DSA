class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int sum = 0;
        int size = INT_MAX;

        for (int h = 0; h < n; h++) {
            sum = sum + nums[h];
            while (sum >= target) {
                size = min(size, h - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        if (size == INT_MAX) {
            size = 0;
        }
        return size;
    }
};