// User function Template for C++

class Solution {
  private:
    int XOR(int r) {
        if(r%4 == 0) return r;
        if(r%4 == 1) return 1;
        if(r%4 == 2) return r+1;
        if(r%4 == 3) return 0;
    }
  public:
    int findXOR(int l, int r) {
        return XOR(r) ^ XOR(l-1);
    }
};