// best

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time= 0;
        for(int i = 1;i < colors.size();++i){
            if(colors[i] == colors[i-1]){
                time += min(neededTime[i],neededTime[i-1]);
                neededTime[i] = max(neededTime[i],neededTime[i-1]);
            }
        }
        return time;
    }
};

// better 

class Solution {
private:
    int sumTime(int s, int e, vector<int>& neededTime) {
        int maxi = 0;
        int sum = 0;
        for (int i = s; i <= e; ++i) {
            sum += neededTime[i];
            maxi = max(maxi, neededTime[i]);
        }
        return sum - maxi; // remove all but one max
    }

public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        int n = colors.size();
        int j = 0; // start of current segment

        for (int i = 1; i <= n; ++i) {
            if (i == n || colors[i] != colors[j]) {
                if (i - j > 1) {
                    time += sumTime(j, i - 1, neededTime);
                }
                j = i;
            }
        }

        return time;
    }
};

// brute force
class Solution {
private:
    int sumTime(int s, int e, vector<int>& neededTime) {
        int maxi = 0;
        for (int i = s; i <= e; i++) {
            maxi = max(maxi, neededTime[i]);
        }
        int sum = 0;
        for (int i = s; i <= e; i++) {
            if (neededTime[i] != maxi) sum += neededTime[i];
        }
        return sum;
    }

public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        int n = colors.size();
        int j = 0; // start of the current segment

        for (int i = 1; i <= n; i++) {
            if (i == n || colors[i] != colors[j]) {
                if (i - j > 1) { // means we have at least 2 same colors
                    time += sumTime(j, i - 1, neededTime);
                }
                j = i; // start of next segment
            }
        }

        return time;
    }
};
