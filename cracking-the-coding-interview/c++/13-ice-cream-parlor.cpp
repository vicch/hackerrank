// Problem:
// To buy 2 ice creams from a series of selections with a certain amount of
// money. Each ice cream has a price. Find out the 2 ice creams that cost
// exactly the amount of money given. Assume there is always a unique solution.
// 
// Example:
// Input: prices = [1, 4, 5, 3, 2], money = 4
// Output: 1 4
// 
// Solution:
// Use hash map to store each price and its position, and look for its pair
// price to add up to the target price, if exists, return the 2 indices,
// otherwise continue.

#include <iostream>
#include <map>

using namespace std;

void get_solution(int* costs, int size, int money)
{
    int i;
    map<int, int> cache;
    map<int, int>::iterator p;
    
    for (i = 0; i < size; i++) {
        if (costs[i] >= money)
            continue;
        p = cache.find(costs[i]);
        if (p != cache.end()) {
            cout << cache[costs[i]] + 1 << " " << i + 1 << endl;
            return;
        } else {
            cache[money - costs[i]] = i;
        }
    }
    
    return;
}

int main()
{
    int time, money, size, i;
    
    cin >> time;
    for (; time > 0; time--) {
        cin >> money >> size;
        int costs[size];
        for (i = 0; i < size; i++)
            cin >> costs[i];
        get_solution(costs, size, money);
    }
    
    return 0;
}
