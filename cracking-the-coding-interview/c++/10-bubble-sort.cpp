// Problem:
// Record the total number of swaps in a bubble sort.
// 
// Example:
// Input: 1 2 3
// Output: Array is sorted in 0 swaps.

using namespace std;

void bsort(vector<int> v)
{
    int swaps, swapsall, i, j;
    
    for (swapsall = i = 0; i < v.size() - 1; i++) {
        
        for (swaps = 0, j = 0; j < v.size() - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                swaps++;
            }
        }

        // Already sorted
        if (swaps == 0)
            break;
        else
            swapsall += swaps;
    }
    
    cout << "Array is sorted in " << swapsall << " swaps." << endl;
    
    return;
}

int main()
{
    int n, i;
    
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++)
       cin >> a[i];
    
    bsort(a);
    
    return 0;
}