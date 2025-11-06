class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(c + 1);
        for (auto& edge : connections) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Find connected components
        vector<int> comp(c + 1, -1);
        int comp_id = 0;
        for (int i = 1; i <= c; ++i) {
            if (comp[i] == -1) {
                queue<int> q;
                q.push(i);
                comp[i] = comp_id;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (int nei : adj[node]) {
                        if (comp[nei] == -1) {
                            comp[nei] = comp_id;
                            q.push(nei);
                        }
                    }
                }
                comp_id++;
            }
        }

        // Step 3: Track online stations for each component
        vector<set<int>> onlineStations(comp_id);
        vector<bool> online(c + 1, true);
        for (int i = 1; i <= c; ++i) {
            onlineStations[comp[i]].insert(i);
        }

        // Step 4: Process queries
        vector<int> result;
        for (auto& q : queries) {
            int type = q[0];
            int x = q[1];
            int cid = comp[x];

            if (type == 1) { // maintenance check
                if (online[x]) {
                    result.push_back(x);
                } else {
                    if (!onlineStations[cid].empty())
                        result.push_back(*onlineStations[cid].begin());
                    else
                        result.push_back(-1);
                }
            } 
            else if (type == 2) {
                if (online[x]) {
                    online[x] = false;
                    onlineStations[cid].erase(x);
                }
            }
        }

        return result;
    }
};
