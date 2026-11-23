class Solution {
public:

    bool helper(vector<int>& weights, int mid, int days) {
        int totalDays = 1;
        int capacity = 0;
        for(int i=0; i<weights.size(); i++) {
            capacity += weights[i];

            if(capacity > mid) {
                totalDays++;
                capacity = weights[i];
            }
        }
        return totalDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN, sum = 0;
        for(int i=0; i<weights.size(); i++) {
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }

        int st = maxi, end = sum;
        int ans = 0;
        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(helper(weights, mid, days)) {
                ans = mid;
                end = mid-1;
            }else {
                st = mid+1;
            }
        }
        return ans;
    }
};