class Solution {
public:
    //Pattern :-> Sliding Window Dynamic 
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, len = 0;
        vector<int> freq(256, 0);

        while (j < s.size()) {
            freq[s[j]]++;

            while (freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }
            len = max(len, (j - i + 1));
            j++;
        }
        return len;
    }
};