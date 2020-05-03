/* Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector <int>> result;
        int n = nums.size();
        if(n <= 2) return {};
        
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n-2; i++){
            if(i==0 || (i!=-0 && nums[i]!=nums[i-1])){
                int low = i+1, high =n-1;
                int remainingSum = 0-nums[i];
                while(low<high){
                    if((nums[low]+nums[high]) == remainingSum){
                        result.push_back({nums[i],nums[low],nums[high]});
                        while(low<high && nums[low] == nums[low+1]) low++;
                        while(low<high && nums[high] == nums[high-1]) high--;
                        low++;
                        high--;
                    }
                    else if((nums[low]+nums[high]) < remainingSum){
                        low++;
                    }
                    else {
                        high--;
                    }
                }
            }
        }
        return result;
    }
};