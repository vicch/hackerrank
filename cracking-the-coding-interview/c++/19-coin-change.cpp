// Problem:
// Given a list of different coin values, find out the number of differenct
// ways to get a given amount. Each coin is available in an infinite quantity.
// 
// Example:
// Input: coins = [1, 2, 3], target = 4
// Output: 4 (1111, 112, 13, 22)
// 
// Solution:
// As the order of coins doesn't matter, it cannot be solved as staircase
// problem. It needs one run on the DP array per coin. For coin value n, for
// each DP slot dp[i] += + dp[i-n].
// 
// Example:
// Input: coins = [1, 2, 3], target = 4
// DP array: [1, 0, 0, 0] // Init 0 as 1
//           [1, 1, 1, 1] // For coin 1 (dp[1] += dp[0], dp[2] += dp[1], ...)
//           [1, 1, 2, 2] // For coin 2 (dp[2] += dp[0], dp[3] += dp[1], ...)
//           [1, 1, 2, 3] // For coin 3 (dp[3] += dp[0])

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long make_change(vector<int> coins, int target)
{
    if (target == 0)
        return 0;

    // sort(coins.begin(), coins.end());

    long cache[target + 1] = {0};
    cache[0] = 1;

    int i, j;

    for (i = 0; i < coins.size(); i++) {
        for (j = coins[i]; j <= target; j++) {
            cache[j] += cache[j - coins[i]];
        }
    }

    return cache[target];
}

int main()
{
    int target, count, i;

    cin >> target >> count;
    vector<int> coins(count);

    for (i = 0; i < count; i++)
        cin >> coins[i];

    cout << make_change(coins, target) << endl;

    return 0;
}