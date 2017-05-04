// Problem:
// In a sequence of integers, all integers come in pairs except for one. Find
// the lonely integer.
// 
// Solution:
// 0 XOR any other number b once, the result is b, XOR b twice, the result is 0.
// Iteratively XOR each number in the sequence, the final result is the lonely
// integer.

#include <iostream>
#include <vector>

using namespace std;

int lonely_integer(vector<int> a)
{
    int n, i;
    
    for (n = i = 0; i < a.size(); i++)
        n ^= a[i];
    
    return n;
}

int main()
{
    int n, i;
    
    cin >> n;
    vector<int> a(n);
    
    for (i = 0; i < n; i++)
       cin >> a[i];
    cout << lonely_integer(a) << endl;
    
    return 0;
}