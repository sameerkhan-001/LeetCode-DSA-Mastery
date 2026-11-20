class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(256, 0);
        int len = 0;    //for storing maximum length
        int n = s.size();
        int maxFreq = 0;    //track maximum freq character
        int i = 0, j = 0;   //window pointers

        while(j < s.size()) {
            freq[s[j]]++;

            maxFreq = max(maxFreq, freq[s[j]]);

            while((j-i+1) - maxFreq > k) {
                freq[s[i]]--;
                i++;
            }
            len = max(len, (j-i+1));
            j++;
        }
        return len;
    }
};