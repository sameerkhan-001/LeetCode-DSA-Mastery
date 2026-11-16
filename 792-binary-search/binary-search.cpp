class Solution {
public:
    // Pattern :-> Classic binary search by (Recursion)
    int recursiveSearch(vector<int>& nums, int low, int high, int target) {
        if (low > high) { // base case
            return -1;
        }
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) { // recursive call
            return recursiveSearch(nums, low, mid - 1, target);
        } else { // recursive call
            return recursiveSearch(nums, mid + 1, high, target);
        }
    }
    int search(vector<int>& nums, int target) {
        return recursiveSearch(nums, 0, nums.size() - 1, target);
    }
};