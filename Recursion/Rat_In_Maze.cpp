class Solution {
  private:
    bool isValid(int i, int j, int n) {
        return i>=0 && i<n && j>=0 && j<n;
    }
    void solve(int i, int j, vector<vector<int>>& maze,int n, string &path, vector<string>&result){
        if(!isValid(i,j,n) || maze[i][j] != 1){
            return;
        }
        if(i == n-1 && j == n - 1) {
            result.push_back(path);
            return;
        }
        
        maze[i][j] = 0;
        
        path.push_back('D');
        solve(i+1,j,maze,maze.size(),path,result);
        path.pop_back();
        
        path.push_back('L');
        solve(i,j-1,maze,maze.size(),path,result);
        path.pop_back();
        
        path.push_back('R');
        solve(i,j+1,maze,maze.size(),path,result);
        path.pop_back();
        
        
        path.push_back('U');
        solve(i-1,j,maze,maze.size(),path,result);
        path.pop_back();
        
        maze[i][j] = 1;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string>result;
        string path;
        solve(0,0,maze,maze.size(),path,result);
        return result;
        
    }
};