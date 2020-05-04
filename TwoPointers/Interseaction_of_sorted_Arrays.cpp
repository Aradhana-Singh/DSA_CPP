/* Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.*/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> result;
    int i=0,j=0;
    while(i<A.size() && j<B.size()){
        if(A[i] == B[j]) {
        result.push_back(A[i]);
        i++;
        j++;
        }
        else if(A[i] < B[j]) i++;
        else j++;
    }
    return result;
}
