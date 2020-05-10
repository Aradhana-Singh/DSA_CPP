//The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, 
//starting from 0 and 1. 
class Solution {
public:
    unordered_map<int,int> mp;
    int fib(int N) {
        if(N==0){
            return 0;
            mp[0]=0;
        }
        if(N==1){
            return 1;
            mp[1]=1;
        }
        if(mp.find(N-1) == mp.end()) mp[N-1] = fib(N-1);
        if(mp.find(N-2) == mp.end()) mp[N-2] = fib(N-2);
        return mp[N-1] + mp[N-2];
        
    }
};