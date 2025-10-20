class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return !(n & (n-1));
    }
};


// if(n & (n-1) == 0) the no. is power of 2
// if (n & (n-1) != 0) the no. is not power of 2