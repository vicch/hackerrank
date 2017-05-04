// Problem:
// Given a staircase, if one can climb 1, 2 or 3 steps at a time, find out the
// total number of ways to climb up the staircase.

#include <iostream>

using namespace std;

int staircase(int n)
{
    int m, m3 = 1, m2 = 2, m1 = 4;

    if (n == 1) return m3;
    if (n == 2) return m2;
    if (n == 3) return m1;

    for (; n > 3; n--) {
        m = m1 + m2 + m3;
        m3 = m2, m2 = m1, m1 = m;
    }

    return m;
}

int main()
{
    int t, n;

    for (cin >> t; t > 0; t--) {
        cin >> n;
        cout << staircase(n) << endl;
    }

    return 0;
}