/*On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. 
You need to find minimum cost to reach the top of the floor, 
and you can either start from the step with index 0, or the step with index 1.*/


//BottomUp or iterative
int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a=cost[0],b = cost[1],temp;
        for(int i = 2; i<n; i++){
            temp = std::min(a,b) + cost[i];
            a = b;
            b = temp;
        }
        return min(a,b);
}

//TopDown or Recursive
    vector<int> memo;
    int fun(vector<int> cost, int i){
        if(i<=1){
            memo[i] = cost[i];
            return memo[i];
        }
        if(memo[i-1]== -1) memo[i-1] = fun(cost,i-1);
        if(memo[i-2]== -1) memo[i-2] = fun(cost,i-2);
        return cost[i] + min(memo[i-1],memo[i-2]);
    }
    int minCostClimbingStairs(vector<int>& cost){
        int n = cost.size();
        cost.push_back(0);
        memo.resize(n+1,-1);
        return fun(cost,n);
    }