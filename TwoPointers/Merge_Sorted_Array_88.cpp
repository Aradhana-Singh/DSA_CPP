/* Given two sorted integer arrays nums1 and nums2, 
merge nums2 into nums1 as one sorted array.

Note:
The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space 
(size that is greater or equal to m + n) 
to hold additional elements from nums2. */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(n+m);
        int i = m-1;
        int j = n-1;
        int lastPos = n+m-1;
        while(i>=0 &&j>=0){
            if(nums1[i]>nums2[j]) nums1[lastPos--] = nums1[i--];
            else nums1[lastPos--] = nums2[j--];
        }
        while(i>=0) nums1[lastPos--] = nums1[i--];
        while(j>=0) nums1[lastPos--] = nums2[j--];
    }
};