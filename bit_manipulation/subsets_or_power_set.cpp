class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subsets = 1<< nums.size();

        vector<vector<int>>ans;
        for(int num = 0; num < subsets;num++){
            vector<int> list;
            for(int i = 0; i<nums.size();i++){
                if(num & (1<<i)){
                    list.push_back(nums[i]);
                }
            }
            ans.push_back(list);
        }
        return ans;
    }
};



class Solution {
private:
    void powerSet(vector<vector<int>>& v,vector<int>& nums,vector<int>& num,int ind){
        v.push_back(num);
        for(int i = ind;i<nums.size();i++){
            num.push_back(nums[i]);
            powerSet(v,nums,num,i+1);
            num.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> curr;
        powerSet(v,nums,curr,0);
        return v;
    }
};