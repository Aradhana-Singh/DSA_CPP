// A peak element is an element that is greater than its neighbors.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0 , high = n-1, mid;
        while(low<high){
            mid = low + (high-low)/2;
            if(nums[mid]<nums[mid+1]) low = mid+1;
            else high = mid;
        }
        return high;
    }
};