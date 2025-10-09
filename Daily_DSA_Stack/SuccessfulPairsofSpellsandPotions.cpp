class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> result;

        for (long long spell : spells) {
            long long minPotion = (success + spell - 1) / spell;

            int index = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();

            int count = m - index;
            result.push_back(count);
        }

        return result;
    }
};