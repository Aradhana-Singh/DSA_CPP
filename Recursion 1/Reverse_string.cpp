/* Write a function that reverses a string. The input string is given as an array of characters char[].
Do not allocate extra space for another array, 
you must do this by modifying the input array in-place with O(1) extra memory.*/
class Solution {
public:
    void reverseStringHelper(vector<char>& s, int low, int high){
        if(low >= high) return;
        swap(s[low],s[high]);
        reverseStringHelper(s,low+1,high-1);
    }
    void reverseString(vector<char>& s) {
        reverseStringHelper(s,0,s.size()-1);
    }
};