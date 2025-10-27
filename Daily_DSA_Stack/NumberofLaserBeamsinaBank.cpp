class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0;

        for (auto &row : bank) {
            int count = 0;
            for (char c : row)
                if (c == '1') count++;

            if (count > 0) {
                ans += prev * count;
                prev = count;
            }
        }
        return ans;
    }
};
