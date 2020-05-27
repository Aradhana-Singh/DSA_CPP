/*You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector <long int> dp(amount+1 , INT_MAX);
        dp[0] = 0;
        for(int amt = 1 ; amt<= amount ; amt++){
            for(int i = 0 ; i<coins.size(); i++){
                if(coins[i] <= amt) 
                    dp[amt] = min( dp[amt] , 1 + dp[amt - coins[i]]);
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};