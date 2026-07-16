class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n - 1;

        while (l < h) {
            int mid = l + (h - l)/ 2;
            if (nums[mid] > nums.back()) l = mid + 1;
            else h = mid;
        }

        int rot = l;
        l = 0, h = n - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            int real = (mid + rot) % n;

            if (nums[real] == target)
                return real;

            if (nums[real] < target) l = mid + 1;
            else h = mid - 1;
        }

        return -1;
    }
};