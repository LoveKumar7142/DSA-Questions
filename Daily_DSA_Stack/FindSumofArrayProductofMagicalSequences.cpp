class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        const long long MOD = 1000000007LL;
        int n = (int)nums.size();
        vector<vector<long long>> C(m+1, vector<long long>(m+1, 0));
        for (int i = 0; i <= m; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }
        vector<vector<long long>> powval(n, vector<long long>(m+1, 1));
        for (int i = 0; i < n; ++i) {
            for (int t = 1; t <= m; ++t) {
                powval[i][t] = (powval[i][t-1] * (nums[i] % MOD)) % MOD;
            }
        }
        int U = m+1, O = m+1, R = m+1;
        auto idx = [&](int used, int ones, int carry) {
            return (used * O + ones) * R + carry;
        };
        int SIZE = U * O * R;

        vector<long long> dp(SIZE, 0), ndp(SIZE, 0);
        dp[idx(0,0,0)] = 1;

        for (int pos = 0; pos < n; ++pos) {
            fill(ndp.begin(), ndp.end(), 0);
            for (int used = 0; used <= m; ++used) {
                for (int ones = 0; ones <= m; ++ones) {
                    for (int carry = 0; carry <= m; ++carry) {
                        long long cur = dp[idx(used, ones, carry)];
                        if (cur == 0) continue;
                        int rem = m - used;
                        for (int t = 0; t <= rem; ++t) {
                            int new_used = used + t;
                            int bit_here = (carry + t) & 1;
                            int new_ones = ones + bit_here;
                            if (new_ones > m) break;
                            int new_carry = (carry + t) >> 1;
                            if (new_carry > m) continue;

                            long long comb = C[rem][t]; 
                            long long pwr = powval[pos][t];
                            long long add = cur;
                            add = (add * comb) % MOD;
                            add = (add * pwr) % MOD;

                            long long &ref = ndp[idx(new_used, new_ones, new_carry)];
                            ref += add;
                            if (ref >= MOD) ref -= MOD;
                        }
                    }
                }
            }
            dp.swap(ndp);
        }
        long long ans = 0;
        for (int ones = 0; ones <= m; ++ones) {
            for (int carry = 0; carry <= m; ++carry) {
                long long val = dp[idx(m, ones, carry)];
                if (val == 0) continue;
                int totalOnes = ones + __builtin_popcountll((unsigned long long)carry);
                if (totalOnes == k) {
                    ans += val;
                    if (ans >= MOD) ans -= MOD;
                }
            }
        }
        return (int)ans;
    }
};
