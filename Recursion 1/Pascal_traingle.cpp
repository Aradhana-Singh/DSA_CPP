/* Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
Note that the row index starts from 0.*/
class Solution {
public:
    vector<int> v;
    vector<int> getRow(int rowIndex) {
        if(rowIndex == -1) {
            vector<int> v;
            v.push_back(1);
            return v;
        }
        getRow(rowIndex-1);
        for(int i = v.size()-1; i>0;i--) v[i]=v[i]+v[i-1];
        v.push_back(1);
        return v;
    }
}; 