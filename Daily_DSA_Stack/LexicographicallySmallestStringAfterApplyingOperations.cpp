class Solution {
public:
    string addOperation(string s, int a) {
        for (int i = 1; i < s.size(); i += 2) {
            int digit = (s[i] - '0' + a) % 10;
            s[i] = digit + '0';
        }
        return s;
    }

    string rotateOperation(string s, int b) {
        int n = s.size();
        return s.substr(n - b) + s.substr(0, n - b);
    }

    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> visited;
        
        string result = s;
        q.push(s);
        visited.insert(s);
        
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            result = min(result, cur);
            string added = addOperation(cur, a);
            if (!visited.count(added)) {
                visited.insert(added);
                q.push(added);
            }
            string rotated = rotateOperation(cur, b);
            if (!visited.count(rotated)) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }
        
        return result;
    }
};
