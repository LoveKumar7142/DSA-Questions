
class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> total;
        for (int x : power) total[x] += x;
        vector<int> keys;
        for (auto &p : total) keys.push_back(p.first);
        sort(keys.begin(), keys.end());
        int n = keys.size();
        vector<long long> dp(n, 0);
        dp[0] = total[keys[0]];

        for (int i = 1; i < n; i++) {
            long long skip = dp[i - 1];
            int j = upper_bound(keys.begin(), keys.end(), keys[i] - 3) - keys.begin() - 1;
            long long take = total[keys[i]] + (j >= 0 ? dp[j] : 0);

            dp[i] = max(skip, take);
        }

        return dp[n - 1];
    }
};
