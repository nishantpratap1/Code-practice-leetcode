#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result = {-1, -1};

    // Find the first occurrence
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (target == nums[mid]) {
            // First occurrence found, update result[0] and search for earlier occurrences
            result[0] = mid;
            high = mid - 1; // Continue searching on the left side
        } else if (target < nums[mid]) {
            high = mid - 1; // Target is on the left side
        } else {
            low = mid + 1; // Target is on the right side
        }
    }

    // Find the last occurrence
    low = 0;
    high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (target == nums[mid]) {
            // Last occurrence found, update result[1] and search for later occurrences
            result[1] = mid;
            low = mid + 1; // Continue searching on the right side
        } else if (target < nums[mid]) {
            high = mid - 1; // Target is on the left side
        } else {
            low = mid + 1; // Target is on the right side
        }
    }

    return result;
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 8, 8, 10};
    int target = 8;

    vector<int> result = searchRange(nums, target);

    cout << "First occurrence: " << result[0] << endl;
    cout << "Last occurrence: " << result[1] << endl;

    return 0;
}
