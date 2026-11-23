class Solution {
public:

    bool func(vector<int>& piles, int mid, int h) {
        double totalHr = 0;

        for(int i=0; i<piles.size(); i++) {
            totalHr += ceil(double(piles[i]) / double(mid));
        }

        return totalHr <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++) {
            maxi = max(maxi, piles[i]);
        }

        int st = 1, end = maxi;
        int ans = 0;
        while(st <= end) {
            int mid = st + (end - st) / 2;

            bool isPossible = func(piles, mid, h);
            if(isPossible == true) {
                ans = mid;
                end = mid-1;
            }else {
                st = mid+1;
            }
        }
        return ans;
    }
};