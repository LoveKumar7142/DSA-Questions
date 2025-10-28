class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int start = 0; start < n; start++) {
            if (nums[start] != 0) continue;
            for (int dir : {-1, 1}) {
                vector<int> temp = nums;
                int curr = start;
                int d = dir;
                while (curr >= 0 && curr < n) {
                    if (temp[curr] == 0) {
                        curr += d;
                    } else {
                        temp[curr]--;
                        d *= -1;
                        curr += d;
                    }
                }
                bool ok = true;
                for (int x : temp) {
                    if (x != 0) {
                        ok = false;
                        break;
                    }
                }
                if (ok) ans++;
            }
        }

        return ans;
    }
};
