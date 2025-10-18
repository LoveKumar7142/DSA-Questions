class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long current = LLONG_MIN; 
        int count = 0;
        
        for (auto num : nums) {
            long long left = (long long)num - k;
            long long right = (long long)num + k;
            long long choose = max(current + 1, left);
            
            if (choose <= right) {
                count++;
                current = choose;
            }
        }
        return count;
    }
};
