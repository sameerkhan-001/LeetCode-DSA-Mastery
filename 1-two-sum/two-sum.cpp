class Solution {
public:

    //Optimal Solution
    //Pattern :-> Hashing (unordered map)
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int comb = target - nums[i];
            if (mp.count(comb)) {
                return {mp[comb], i};
                break;
            }

            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};