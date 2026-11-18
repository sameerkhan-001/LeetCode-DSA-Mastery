class Solution {
public:
    //Pattern :-> Unordered Set
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;

        for(auto it : st) {
            if(st.find(it-1) == st.end()) { //it is the starting point of curr seq
                int len = 1;
                while(st.find(it+len) != st.end()) {    //we got another seq ele
                    len++; //increase seq len
                }
                ans = max(ans, len);    //store max len of seq
            }
        }

        return ans; //return maximum len of seq
    }
};