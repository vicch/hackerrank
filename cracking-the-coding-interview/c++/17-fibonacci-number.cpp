// Problem:
// 

#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if (n < 3)
        return 1;

    int a, b, c;

    for (a = b = 1; n > 2; n--) {
        c = a + b;
        a = b, b = c;
    }

    return c;
}

int main()
{
    int n;

    cin >> n;
    cout << fibonacci(n) << endl;

    return 0;
}