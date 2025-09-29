class Solution {
private:
    int t[51][51];
    int solve(vector<int>& values,int i,int j){
        if(j-i+1 < 3) return 0;
        int result = INT_MAX;

        if(t[i][j] != -1) return t[i][j];

        for(int k = i+1;k<j;k++){
            int wt = values[i]*values[j]*values[k] + solve(values,i,k) + solve(values,k,j);
            result = min(result,wt);
        }
        return t[i][j] = result;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(t,-1,sizeof(t));
        return solve(values,0,n-1);
    }
};