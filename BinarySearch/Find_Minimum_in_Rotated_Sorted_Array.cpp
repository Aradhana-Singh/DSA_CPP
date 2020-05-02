//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
/*Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low =0, high = n-1, mid;
        while(low < high){
            mid = low + (high-low)/2;
            if(nums[mid] > nums[high])
                low = mid+1;
            else high = mid;
        }
        return nums[high];
    }
};