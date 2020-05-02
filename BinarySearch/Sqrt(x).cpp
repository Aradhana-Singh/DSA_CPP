// Implement int sqrt(int x).

class Solution {
public:
    int mySqrt(int x) {
        long long int low = 0 , high = x, mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if( mid*mid == x) return mid;
            else if(mid*mid < x) low = mid +1;
            else high = mid-1;
        }
        return high;
    }
};