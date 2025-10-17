class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();

        vector<unordered_map<int, int>> dp_no_change(n + 1), dp_used_change(n + 1);
        dp_no_change[0][0] = 0;
        dp_used_change[0][0] = 0;

        for (int i = 0; i < n; ++i) {
            int cur = s[i] - 'a';
            for (auto &[mask, parts] : dp_no_change[i]) {
                int newMask = mask | (1 << cur);
                if (__builtin_popcount(newMask) <= k)
                    dp_no_change[i + 1][newMask] = max(dp_no_change[i + 1][newMask], parts);
                else
                    dp_no_change[i + 1][1 << cur] = max(dp_no_change[i + 1][1 << cur], parts + 1);
                for (int ch = 0; ch < 26; ++ch) {
                    if (ch == cur) continue;
                    int newMask2 = mask | (1 << ch);
                    if (__builtin_popcount(newMask2) <= k)
                        dp_used_change[i + 1][newMask2] = max(dp_used_change[i + 1][newMask2], parts);
                    else
                        dp_used_change[i + 1][1 << ch] = max(dp_used_change[i + 1][1 << ch], parts + 1);
                }
            }
            for (auto &[mask, parts] : dp_used_change[i]) {
                int newMask = mask | (1 << cur);
                if (__builtin_popcount(newMask) <= k)
                    dp_used_change[i + 1][newMask] = max(dp_used_change[i + 1][newMask], parts);
                else
                    dp_used_change[i + 1][1 << cur] = max(dp_used_change[i + 1][1 << cur], parts + 1);
            }
        }

        int ans = 0;
        for (auto &[mask, parts] : dp_no_change[n])
            ans = max(ans, parts + 1);
        for (auto &[mask, parts] : dp_used_change[n])
            ans = max(ans, parts + 1);

        return ans;
    }
};
