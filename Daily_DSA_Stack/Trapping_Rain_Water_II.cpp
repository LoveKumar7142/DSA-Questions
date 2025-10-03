class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; 
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m-1][j], m-1, j});
            visited[0][j] = visited[m-1][j] = true;
        }

        int water = 0;
        vector<int> dir = {0, 1, 0, -1, 0};

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int h = cur[0], r = cur[1], c = cur[2];

            for (int k = 0; k < 4; k++) {
                int nr = r + dir[k], nc = c + dir[k+1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) continue;
                
                visited[nr][nc] = true;
                water += max(0, h - heightMap[nr][nc]);
                pq.push({max(h, heightMap[nr][nc]), nr, nc});
            }
        }

        return water;
    }
};
