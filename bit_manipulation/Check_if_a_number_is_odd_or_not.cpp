// if the number is even so it gives true esle false 

class Solution {
  public:
    bool isEven(int n) {
        // code here
        return !(n&1);
    }
};

// if(n&1 == 1) then the no. is odd
// if(n&1 == 0) then the no. is even