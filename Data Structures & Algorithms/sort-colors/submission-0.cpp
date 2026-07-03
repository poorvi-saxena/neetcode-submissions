
class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int red=0, blue=n-1;

        int i = 0;

        while(i<=blue && i<n) {
            if(nums[i] == 2) {
                swap(nums, i, blue);
                blue--;
                // element from the end has to be processed again hence no i++
            } else if(nums[i] == 0) {
                swap(nums, i, red);
                red++;
                i++;
            } else i++;
        }
    }
};