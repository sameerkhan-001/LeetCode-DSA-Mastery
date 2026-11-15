class Solution {
public:

    //Optimal Solution

    //Pattern :-> Hashing (unordered map)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            int comb = target - nums[i];
            if (m.count(comb)) {
                return {m[comb], i};
                break;
            }

            m[nums[i]] = i;
        }
        return {-1, -1};
    }
};