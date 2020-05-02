/*
 There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        
        int low = 0, high = n, px,py,maxx,maxy,minx,miny;
        while(low<=high){
            px = low + (high -low)/2;
            py = (n+m+1)/2 - px;
            
            if(px == n) maxx = INT_MAX;
            else maxx = nums1[px];
            if(px == 0) minx = INT_MIN;
            else minx = nums1[px-1];
            if(py == 0) miny = INT_MIN;
            else miny = nums2[py-1];
            if(py == m) maxy = INT_MAX;
            else maxy = nums2[py];
            
            if(minx <= maxy && miny <= maxx){
                if((n+m)%2 == 0 ){
                    return (max(minx,miny)+min(maxx,maxy))/2.0;
                }
                else{
                    return max(minx,miny);
                }
            }
            else if( minx > maxy){
                high = px-1;
            }
            else{
                low = px+1;
            }
        }
        return -1;
    }
};