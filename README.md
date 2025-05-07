
# Cascade Search Algorithm

## Overview

The **Cascade Search** algorithm is a novel searching technique that progressively narrows down the search space by cascading through multiple segments or buckets. Unlike traditional search methods such as linear or binary search, Cascade Search uses a series of filters that refine the search progressively, allowing it to efficiently search through larger datasets.

The algorithm divides the array into multiple segments, applies a series of threshold checks (cascading filters) for each segment, and then searches within the narrowed segment. This method allows for both structured and flexible searching.

## Features

- **Divides the dataset into segments**: The array is divided into multiple segments, allowing for more focused searching.
- **Cascading filters**: The search progressively narrows to the relevant segment based on predefined thresholds.
- **Efficient searching**: After filtering, a linear search is performed within the relevant segment.
- **Configurable segment count**: The number of segments (`k`) can be adjusted, allowing for tuning the granularity of the search.

## How It Works

1. **Divide the Array**: The input array is divided into `k` segments. Each segment is processed in sequence.
2. **Apply Cascading Filters**: For each segment, check if the target lies within the range of values in that segment. If it does, search within the segment.
3. **Search Within the Segment**: If the target lies within a segment, a linear search is performed within that segment.
4. **Return the Index**: If the element is found, its index is returned. Otherwise, if no segment contains the target element, return `-1`.

## Example

Given an array `{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}` and a target `7`, and using `k = 3` segments:

1. **Divide into Segments**:
   - Segment 1: `{1, 2, 3}`
   - Segment 2: `{4, 5, 6}`
   - Segment 3: `{7, 8, 9, 10}`

2. **Cascading Filters**:
   - For Segment 1: `7` is not in the range.
   - For Segment 2: `7` is not in the range.
   - For Segment 3: `7` is found in the range. Perform a linear search within Segment 3.

3. **Result**:
   - The target `7` is found at index `6`.

### Example Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int cascadeSearch(const vector<int>& arr, int target, int k) {
    int n = arr.size();
    
    // Step 1: Divide the array into k segments
    int segmentSize = n / k;
    vector<pair<int, int>> thresholds;  // (start, end) pairs for each segment
    
    for (int i = 0; i < k; i++) {
        int start = i * segmentSize;
        int end = (i == k - 1) ? n - 1 : (i + 1) * segmentSize - 1;
        thresholds.push_back({start, end});
    }

    // Step 2: Apply cascading filters
    for (auto& threshold : thresholds) {
        int start = threshold.first;
        int end = threshold.second;
        
        // Filter: Check if the target lies within this segment's range
        if (arr[start] <= target && arr[end] >= target) {
            // Step 3: Search within the selected segment
            for (int i = start; i <= end; i++) {
                if (arr[i] == target) {
                    return i;  // Target found
                }
            }
        }
    }
    
    return -1;  // Target not found
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    int k = 3; // Divide into 3 segments
    
    int result = cascadeSearch(arr, target, k);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
```

## Time Complexity

- **Worst-case time complexity**: O(n/k + k * (n/k)) = O(n)
  - Where `n` is the size of the array and `k` is the number of segments. The worst-case time complexity is linear in terms of the array size.

## Space Complexity

- **Space Complexity**: O(k)
  - The space complexity is proportional to the number of segments `k` because we store the thresholds for each segment.

## Use Cases

- **Large Datasets**: Cascade Search is particularly useful when dealing with large datasets that can be divided into smaller, manageable chunks.
- **Distributed Searching**: In distributed systems where data is partitioned across multiple locations or nodes, the Cascade Search algorithm can be used to efficiently narrow down the search space.
- **Dynamic Adjustment**: The number of segments `k` can be dynamically adjusted depending on the available memory, the dataset size, or the performance needs.

## License

This project is licensed under the MIT License.
