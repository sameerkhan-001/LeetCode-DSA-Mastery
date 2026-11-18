class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        //store all nums ele's in set st
        for(auto it : nums) st.insert(it);
        int len;
        int maxLen = 0;
        
        for(auto it : st) {
            if(st.find(it - 1) == st.end()) {   //starting point
                len = 0;
                while(st.find(it + len) != st.end()) len++;

                maxLen = max(maxLen, len);
            }
        }

        return maxLen; 
    }
};