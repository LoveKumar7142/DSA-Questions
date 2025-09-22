class Solution {
    vector<string> ans;
private:
    void solve(string &num,int target,int ind, string path,long eval, long residual){
        if(ind == num.length()){
            if(eval == target){
                ans.push_back(path);
                return;
            }
        }

        string currStr;
        long number = 0;

        for(int i = ind;i<num.length();i++){
            if(i>ind && num[i] == '0') return;
            currStr+=num[i];
            number = number*10 + num[i] - '0';
            if(i == 0){
                solve(num,target,i+1,path + currStr,number,number);
            }else{
                solve(num,target,i+1,path+ "+" + currStr,eval+number,number);
                solve(num,target,i+1,path+ "-" + currStr,eval-number,-number);
                solve(num,target,i+1,path+ "*" + currStr,eval-residual + residual* number,residual*number);

            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        solve(num,target,0,"",0,0);
        return ans;
    }
};