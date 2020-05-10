/*You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.*/

class Solution {
public:
    unordered_map<int,int> mp;
    int climbStairs(int n) {
        if(n==1) {
            mp[1] = 1;
            return 1;
        }
        if(n==2) {
            mp[2] = 1;
            return 2;
        }
        if(mp.find(n-1)==mp.end()) mp[n-1] = climbStairs(n-1);
        if(mp.find(n-2)==mp.end()) mp[n-2] = climbStairs(n-2);
        return mp[n-1]+mp[n-2];
    }
};