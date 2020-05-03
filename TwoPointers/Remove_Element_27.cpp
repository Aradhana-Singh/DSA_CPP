/* Given an array nums and a value val, 
remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, 
you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fptr = 0, sptr=0, n = nums.size();
        while(sptr<n){
            if(nums[sptr]!=val){
                nums[fptr] = nums[sptr];
                fptr++;
                sptr++;
            }
            else{
                sptr++;
            }
        }
        return fptr;
    }
};