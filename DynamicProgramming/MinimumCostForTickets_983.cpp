class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        if(n == 0) return 0;
        int m = days[n-1];
        int dp[m+1];
        vector <bool> isTravelDay(m+1,false);
        for(auto i : days) isTravelDay[i] = true;
        dp[0] = 0;
        for(int i = 1; i<=m; i++){
            if(!isTravelDay[i]) dp[i]=dp[i-1];
            else{
                int ans1 = dp[i-1] + costs[0];
                int ans2 = dp[ ( i-7>0 ? i-7 : 0 ) ] + costs[1];
                int ans3 = dp[( i-30>0 ? i-30 : 0 )] + costs[2];
                dp[i] = min(min(ans1,ans2),ans3);
            }
        }
        return dp[m];
    }
};