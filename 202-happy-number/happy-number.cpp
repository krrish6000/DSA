class Solution {
private:
    // Helper function to calculate sum of squared digits
    int ss(int n) {
        int sum = 0;
        while (n > 0) {
            int dig = n % 10;
            sum += dig * dig;
            n /= 10;
        }
        return sum; // Must return AFTER the loop finishes!
    }

public:
    bool isHappy(int n) {
        int slow = ss(n);
        int fast = ss(ss(n));

        while (slow != fast) {
            slow = ss(slow);
            fast = ss(ss(fast));
        }

        return slow == 1;
    }
};