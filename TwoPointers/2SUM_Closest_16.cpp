/* Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.*/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0, dif = INT_MAX;
        if(n<3) return 5;
        sort( nums.begin() , nums.end() );
        for(int i = 0 ; i < n-2 ; i++){
            int low = i+1 ,high = n-1;
            while(low < high){
                if(dif > abs(nums[i]+nums[low]+nums[high]-target)){
                    dif = abs(nums[i]+nums[low]+nums[high]-target);
                    sum = nums[i]+nums[low]+nums[high];
                    if(nums[i]+nums[low]+nums[high] < target) low++;
                    else high--;
                }
                else if(nums[i]+nums[low]+nums[high] < target){
                    low++;
                }
                else high--;
            }
        }
        return sum;
    }
};