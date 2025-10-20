// 🥇 1️⃣ HashMap / Frequency Count (Naive, Simple but O(n) Space)
// 💡 Idea

// Count how many times each number appears.
// Return the one with frequency = 1.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int n : nums) mp[n]++;
        for (auto& it : mp)
            if (it.second == 1) return it.first;
        return -1;
    }
};


// 🥈 2️⃣ Sorting-based Approach
// 💡 Idea

// If we sort the array, elements appear in groups of 3 — except one.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size()-1; i += 3) {
            if (nums[i] != nums[i-1]) return nums[i-1];
        }
        return nums.back();
    }
};


// 🥉 3️⃣ Bit Counting (Mod 3 Method) — 32-bit
// 💡 Idea

// Count 1s for each bit position, take mod 3 → keep remaining bits.
// We’ve already done this one.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int num : nums) {
                if (num >> i & 1)
                    sum++;
            }
            if (sum % 3)
                result |= (1 << i);
        }
        if (result >= (1 << 31))
            result -= (1LL << 32);

        return result;
    }
};


// 🏆 4️⃣ Bitwise State Machine (Ones-Twos Method)
// 💡 Idea

// Use two variables to track how many times each bit appears (mod 3).

// Each bit cycles through 3 states:

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0,twos = 0;

        for(auto& num : nums){
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};



// 🧮 5️⃣ Mathematical Approach (Sum Trick)
// 💡 Idea

// If 3 * sum(set(nums)) - sum(nums) gives 2 * single,
// then single = (3 * sum(set(nums)) - sum(nums)) / 2.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long sumSet = 0, sumAll = 0;
        unordered_set<int> s;
        for (int x : nums) {
            s.insert(x);
            sumAll += x;
        }
        for (int x : s) sumSet += x;
        return (int)((3 * sumSet - sumAll) / 2);
    }
};
