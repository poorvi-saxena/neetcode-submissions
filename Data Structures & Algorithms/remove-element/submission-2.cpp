




class Solution {
    public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int l=0, r=n-1;
        int count=0;
        
        if(n==0) return 0;
        if(n==1) return nums[0] == val ? 0 : 1;

        while(l<r) {
            if(nums[r] == val) {
                r--;
                count++;
            }
            else if(nums[l] == val) {
                nums[l] = nums[r];
                r--; 
                count++;
            } else {
                l++;
            }
        }
        if(l<n && nums[l] == val) count++;
        return n - count;
    }
};