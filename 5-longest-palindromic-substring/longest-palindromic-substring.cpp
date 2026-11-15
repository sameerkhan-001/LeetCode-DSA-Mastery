class Solution {
private:
    // Expand around the given center and return the palindrome
    string helper(int j, int k, string& s) {
        int n = s.size();
        string curr = "";

        while(j >= 0 && k < n) {
            if(s[j] == s[k]) {  // expand if both characters match

                if(j == k) {
                    curr += s[j];  // store center character
                    j--, k++;      // expand in both directions
                }else {
                    curr.insert(curr.begin(), s[j]);  // add left character
                    curr += s[k];                     // add right character
                    j--, k++;                         // expand in both directions
                }

            }else {
                break;  // palindrome breaks
            }
        }

        return curr;
    }

public:

    // Pattern :-> Expand Around Center
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        for(int i = 0; i < n; i++) {

            string curr = helper(i, i, s);        // odd-length palindrome
            string curr2 = helper(i, i + 1, s);  // even-length palindrome

            if(ans.size() < curr.size()) {  // update if odd palindrome is longer
                ans = curr;
            }

            if(ans.size() < curr2.size()) {  // update if even palindrome is longer
                ans = curr2;
            }
        }

        return ans;
    }
};