class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        vector<long long> f(n, 0);

        for (int x : mana) {
            long long now = f[0];
            for (int i = 1; i < n; ++i) {
                now = max(now + (long long)skill[i - 1] * x, f[i]);
            }
            now += (long long)skill[n - 1] * x;
            f[n - 1] = now;

            for (int i = n - 2; i >= 0; --i) {
                f[i] = f[i + 1] - (long long)skill[i + 1] * x;
            }
        }

        return f[n - 1];
    }
};
