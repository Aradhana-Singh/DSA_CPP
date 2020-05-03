/* Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, 
which together with x-axis forms a container, 
such that the container contains the most water.*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int max_so_far = 0;
        while(i < j){
            max_so_far = max ( max_so_far , min(height[i],height[j])*(j-i) ) ;
            if(height[j]>height[i]) i++;
            else j--;
        }
        return max_so_far;
    }
};