/* Given a sorted array nums, 
remove the duplicates in-place such that each element appear only once 
and return the new length.

Do not allocate extra space for another array, 
you must do this by modifying the input array in-place with O(1) extra memory.*/

class Solution {
public:
    int removeDuplicates(vector <int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        int first = 1,second = 1;
        while(second < n){
            if(nums[second] == nums[second-1]) second++;
            else {
                nums[first] = nums[second];
                first++;
                second++;
            }
        }
        return first;
    }
};