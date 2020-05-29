// LONGEST COMMON SUBSEQUENCE 

// Bottom-Up approch
int longestCommonSubsequence(string text1, string text2) {
        int dp[text1.size()+1][text2.size()+1];
        for(int i = 0; i<=text1.size(); i++) dp[i][0] =0;
        for(int i = 0; i<=text2.size(); i++) dp[0][i] =0;
        for(int i = 1; i<=text1.size(); i++){
            for(int j = 1; j<=text2.size(); j++){
                if(text1[i-1] == text2[j-1]) 
                    dp[i][j] =dp[i-1][j-1]+1;
                else 
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }

//Top-Down Approch
vector<vector<int> > dp ;
    int fun(string x , int i, string y, int j){
        if(i == -1 || j == -1) return 0;
        if(x[i] == y[j]){
            if(dp[i][j] == -1) dp[i][j] =  fun(x, i-1, y, j-1);
            return 1 + dp[i][j];
        }
        else{
            if(dp[i][j+1] == -1) dp[i][j+1] =  fun(x, i-1, y, j);
            if(dp[i+1][j] == -1) dp[i+1][j] =  fun(x, i, y, j-1);
            return max(dp[i+1][j] , dp[i][j+1]);
        }
    }
    int longestCommonSubsequence(string text1, string text2){
        dp.resize(text1.size()+1, vector <int> (text2.size()+1,-1));
        return fun(text1 , text1.size()-1 , text2 , text2.size()-1);
       
    }