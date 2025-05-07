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
