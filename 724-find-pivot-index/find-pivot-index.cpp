class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        int left=0;
        for(int k=0;k<nums.size();k++) {
            sum=sum+nums[k];
        }
        for(int i=0;i<nums.size();i++) {
            int right=sum-left-nums[i];
            if(left==right) {
                return i;
            }
            left=left+nums[i];
        }
        return -1;
    }
};