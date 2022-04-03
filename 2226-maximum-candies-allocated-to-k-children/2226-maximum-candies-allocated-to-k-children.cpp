class Solution {
public:
    int maximumCandies(vector<int>& c, long long k) {
        long l = 1, r = *max_element(c.begin(), c.end()), n = c.size();
        auto valid = [&](long m) {
            long cnt = 0;
            for (int n : c) {
                cnt += n / m;
                if (cnt >= k) return true;
            }
            return false;
        };
        while (l <= r) {
            long mid = l + (r - l) / 2;
            if (valid(mid)) 
            l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};