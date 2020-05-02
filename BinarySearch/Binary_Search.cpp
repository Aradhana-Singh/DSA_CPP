//Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to
//search target in nums. If target exists, then return its index, otherwise return -1.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1, mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};