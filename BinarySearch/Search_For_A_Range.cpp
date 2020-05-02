/* Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
       int low = 0, high = nums.size()-1, mid, start=-1, end =-1;
        while(low<high){
            mid = low + (high-low)/2;
            if(nums[mid] < target) low = mid + 1;
            else high = mid;
        }
        if(nums[high] == target)
        start = high;
        low = 0, high = nums.size()-1;
        while(low + 1 < high){
            mid = low + (high-low)/2;
            if(nums[mid] > target) high = mid-1;
            else low = mid;
        }
        if(nums[high] == target)
        end = high;
        else if (nums[low] == target) end = low;
        return {start,end};
    }
};