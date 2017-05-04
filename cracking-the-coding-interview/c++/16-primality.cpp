// Problem:
// Determine if a given integer is prime.
// 

#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
    if (n == 1)
        return false;

    int i, r;

    for (r = sqrt(n), i = 2; i <= r; i++)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    int t, n;

    cin >> t;
    for (; t > 0; t--) {
        cin >> n;
        cout << (is_prime(n) ? "Prime" : "Not prime") << endl;
    }

    return 0;
}