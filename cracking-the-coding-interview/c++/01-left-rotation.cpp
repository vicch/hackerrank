// Problem:
// A left rotation operation on an array of size n shifts each of the array's
// elements 1 unit to the left. Given an array of n integers and a number k,
// perform k left rotations on the array.
// 
// Example:
// Input: [1, 2, 3, 4, 5], n = 5, k = 4
// Output: [5, 1, 2, 3, 4]
// 
// Solution:
// Actual left rotation k = k % n. if k == 0, return as if. Otherwise, create a
// new array in 2 steps: first the later part of original array, then the rest.

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    k %= n;
    
    if (k == 0)
        return a;
    
    int i;
    vector<int> v(n);
    
    for (i = 0; i < n - k; i++)
        v[i] = a[i + k];
    
    for (i = n - k; i < n; i++)
        v[i] = a[i + k - n];
    
    return v;
}