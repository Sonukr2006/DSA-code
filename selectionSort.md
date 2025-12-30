
# Selection Sort

Selection Sort is a simple comparison-based sorting algorithm. It divides the input array into two parts: the subarray of items already sorted (built from left to right) and the subarray of items remaining to be sorted. The algorithm repeatedly selects the smallest (or largest, for descending order) element from the unsorted part and swaps it with the first element of the unsorted part.

## How it works (step-by-step)

1. Start with the first element (index 0). Consider this the boundary between the sorted and unsorted regions.
2. Find the minimum element in the unsorted region (from the boundary to the end of the array).
3. Swap that minimum element with the element at the boundary (placing the minimum into the sorted region).
4. Move the boundary one element to the right and repeat until the whole array is sorted.

Example: Sort [64, 25, 12, 22, 11]

- i = 0: find min in [64,25,12,22,11] → min = 11 at index 4 → swap arr[0] and arr[4]
	array becomes [11,25,12,22,64]
- i = 1: find min in [25,12,22,64] → min = 12 at index 2 → swap arr[1] and arr[2]
	array becomes [11,12,25,22,64]
- i = 2: find min in [25,22,64] → min = 22 → swap arr[2] and arr[3]
	array becomes [11,12,22,25,64]
- i = 3: find min in [25,64] → min = 25 → swap (no change)
- Sorted: [11,12,22,25,64]

## Complexity

- Time complexity:
	- Best: O(n^2)
	- Average: O(n^2)
	- Worst: O(n^2)
- Space complexity: O(1) (in-place)
- Stability: Selection sort is NOT stable by default because it swaps non-adjacent elements. A stable variant is possible but requires extra work.

## When to use

- Only useful for small arrays or when memory writes are more expensive than reads (selection sort does at most n swaps). For large arrays, prefer O(n log n) algorithms like quicksort, mergesort, or heapsort.

## Common pitfalls / edge cases

- Empty array and single-element array should be handled naturally — algorithm will do nothing.
- Duplicates are fine, but selection sort may change their relative order (not stable).
- Ensure loops handle unsigned types/size() safely in C++.

## Corrected C++ implementation

The attached `selectionSort.cpp` had a bug: inside the inner loop it compared `arr[i] > arr[j]` and swapped `arr[minIndex]` with `arr[j]` without updating `minIndex`. The correct logic is to compare `arr[j]` with `arr[minIndex]` and update `minIndex` accordingly, then after the inner loop swap `arr[i]` and `arr[minIndex]` if needed.

Here's a clean, corrected version:

```cpp
#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
		int n = (int)arr.size();
		for (int i = 0; i < n - 1; ++i) {
				int minIndex = i;
				for (int j = i + 1; j < n; ++j) {
						if (arr[j] < arr[minIndex]) {
								minIndex = j;
						}
				}
				if (minIndex != i) swap(arr[i], arr[minIndex]);
		}
}

int main() {
		int n;
		cout << "Enter Your Array Size: ";
		if (!(cin >> n) || n <= 0) return 0;

		vector<int> arr;
		arr.reserve(n);
		for (int i = 0; i < n; ++i) {
				int val;
				cout << "Enter Your Val : ";
				cin >> val;
				arr.push_back(val);
		}

		selectionSort(arr);

		cout << "Sorted array: ";
		for (int val : arr) cout << val << " ";
		cout << endl;
		return 0;
}
```

### Example run

Input:
```
Enter Your Array Size: 5
Enter Your Val : 64
Enter Your Val : 25
Enter Your Val : 12
Enter Your Val : 22
Enter Your Val : 11
```

Output:
```
Sorted array: 11 12 22 25 64
```

## Next steps (optional)

- Add a unit-test or quick-run script to demonstrate the algorithm with random arrays.
- Implement a stable selection sort variant if stability is required.

