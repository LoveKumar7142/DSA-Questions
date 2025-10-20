
// using rightShift
class Solution {
  public:
    bool checkKthBit(int n, int k) {
        return ((n>>k) & 1) != 0;
    }
};


// using left Shift
class Solution {
  public:
    bool checkKthBit(int n, int k) {
        return (n & (1<<k)) != 0;
    }
};