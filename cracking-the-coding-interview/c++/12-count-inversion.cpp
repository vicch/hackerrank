// Problem:
// Assume a method of sorting an array of integers by swapping 2 adjacent
// numbers if they are "out of order", count how many swaps are needed to sort
// the whole array into order.
// 
// Example:
// Input: 2, 1, 3, 1, 2
// Output: 4, steps:
// 2, 1, 3, 1, 2
// 1, 2, 3, 1, 2
// 1, 2, 1, 3, 2
// 1, 1, 2, 3, 2
// 1, 1, 2, 2, 3
// 
// Solution:
// The problem is actually: for each index, count how many numbers from a[0] to
// a[i-1] are greater than a[i], and return the total number. This number can
// be counted by sorting the array with merge sort. In the merging part, every
// time a number from the right half is chosen, it means there are greater
// numbers in the left half, and the number can be know by the running indices.
// Return the number to upper level when recursive merge sort returns.

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

long merge_sort(vector<int>& v, int l, int r)
{
    if (l == r)
        return 0;

    int m, i, j, k;
    long c;

    m = (l + r) / 2;
    c = merge_sort(v, l, m) + merge_sort(v, m + 1, r);

    vector<int> tmp(r - l + 1);
    for (i = l, j = m + 1, k = 0; k < tmp.size(); k++) {
        if (i > m)
            tmp[k] = v[j++];
        else if (j > r)
            tmp[k] = v[i++];
        else if (v[j] >= v[i])
            tmp[k] = v[i++];
        else {
            c += m - i + 1;
            tmp[k] = v[j++];
        }
    }

    for (i = 0; i < tmp.size(); i++, l++)
        v[l] = tmp[i];
    
    return c;
}

long count_inversions(vector<int> v)
{
    return merge_sort(v, 0, v.size() - 1);
}

int main()
{
    int n, m, i;

    for (cin >> n; n > 0; n--) {
        cin >> m;
        vector<int> v(m);
        for (i = 0; i < m; i++)
           cin >> v[i];
        cout << count_inversions(v) << endl;
    }

    return 0;
}