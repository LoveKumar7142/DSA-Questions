class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;

        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = 1;

        int res = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto [t, pos] = pq.top(); pq.pop();
            int i = pos.first, j = pos.second;
            res = max(res, t);

            if (i == n - 1 && j == n - 1) return res;

            for (auto &d : dirs) {
                int x = i + d[0], y = j + d[1];
                if (x >= 0 && y >= 0 && x < n && y < n && !visited[x][y]) {
                    visited[x][y] = 1;
                    pq.push({grid[x][y], {x, y}});
                }
            }
        }
        return res;
    }
};
