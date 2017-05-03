// Problem:
// Given a stream of integers, perform the following task for each integer:
// - Add the integer to a running list of integers.
// - Find and print the median of the updated list as a double-precision number
//   scaled to decimal place.
// 
// Example:
// Input: 12 4 5 3 8 7
// Output: 12.0 8.0 5.0 4.5 5.0 6.0
// 
// Solution:
// Separate all numbers into 2 parts, the median is determined by the largest
// number from the smaller half and the smallest number from the larger half.
// Use 2 vectors (arrays) to implement the max and min heap, and balance them
// to equal size (even numbers) or one contains one more number than the other
// (odd numbers).

#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>

using namespace std;

// Get parent, left child, right child node index
#define PAR(n) ((n - 1) / 2)
#define LCH(n) (n * 2 + 1)
#define RCH(n) ((n + 1) * 2)

class MedianHeap {
protected:
    vector<int> lheap, rheap;

    int top(vector<int>& heap)
    {
        return (heap.size() ? heap[0] : 0);
    }

    int pop(vector<int>& heap, int s)
    {
        if (!heap.size())
            return 0;

        int n, i, j, k;

        n = heap[0];

        // Move last element to head
        heap[0] = heap[heap.size() - 1];
        heap.erase(heap.end() - 1);

        if (heap.size()) {
            for (
                i = 0, j = LCH(i), k = RCH(i);
                // If there is at least one child node, and current node should be swapped with one of them
                (j < heap.size() && (heap[i] - heap[j]) * s < 0) || (k < heap.size() && (heap[i] - heap[k]) * s < 0);
                j = LCH(i), k = RCH(i)
            ) {
                // If right child node does not exist, or left child node is more proper to be swapped with current node
                if (k >= heap.size() || (heap[k] - heap[j]) * s < 0) {
                    swap(heap[i], heap[j]);
                    i = j;
                // If right child node exists, and is more proper to be swapped with current node
                } else {
                    swap(heap[i], heap[k]);
                    i = k;
                }
            }
        }

        return n;
    }

    void push(vector<int>& heap, int n, int s)
    {
        int i, j;

        heap.push_back(n);

        for (
            i = heap.size() - 1, j = PAR(i);
            // If current node is not the top, and should be swapped with its parent node
            j >= 0 && (heap[i] - heap[j]) * s < 0;
            i = j, j = PAR(i)
        )
            swap(heap[i], heap[j]);

        return;
    }

public:
    void add(int n)
    {
        if (n > median())
            push(rheap, n, 1);
        else
            push(lheap, n, -1);

        // If number is odd, keep left heap size == right heap size + 1
        // If number is even, keep left heap size == right heap size
        if (rheap.size() > lheap.size())
            push(lheap, pop(rheap, -1), -1);
        else if (lheap.size() > rheap.size() + 1)
            push(rheap, pop(lheap, 1), 1);

        cout << fixed << setprecision(1) << median() << endl;

        return;
    }

    float median()
    {
        // If number is odd
        if (lheap.size() > rheap.size())
            return top(lheap) * 1.0;
        // If number is even
        else
            return (top(lheap) + top(rheap)) * 1.0 / 2;
    }
};

int main()
{
    int n, v, i;
    MedianHeap mh;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> v;
        mh.add(v);
    }

    return 0;
}