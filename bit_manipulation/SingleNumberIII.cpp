class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long XORR = 0;
        for(int i = 0;i<nums.size();i++) XORR ^= nums[i];
        
        int rightMost = (XORR & (XORR - 1)) ^ XORR;
        int b1 = 0,b2 = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] & rightMost) b1 ^= nums[i];
            else b2 ^= nums[i];
        }
        return {b1,b2};
    }
};