class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        if(m == 1){
            for(int i = 1; i< n ; i++) {
                A[i][0] += A[i-1][0];
            }
            return A[n-1][0];
        }
        for(int i = 1; i<n; i++){
            A[i][0] += min(A[i-1][0] , A[i-1][1]);
            for(int j =1; j<m-1; j++){
                A[i][j] +=  min (min(A[i-1][j-1], A[i-1][j]) , A[i-1][j+1]);
            }
            A[i][m-1] += min(A[i-1][m-2] , A[i-1][m-1]);
        }
        return *min_element(A[n-1].begin() , A[n-1].end());
    }
};