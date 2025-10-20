// brute force simple HCF of N if rem = 1 cnt ++ 

class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n != 1){
            if(n%2 == 1) cnt+=1;
            n /= 2;
        }
        if(n == 1) cnt+= 1;
        return cnt;
    }
};


// better  -> n % 2 == 1 is check odd so we use n&1 == 1 that is also check odd
//  And the second is we use right shift operator >> 
// n /= 2 => n = n rightshift 1 => n = n >> 1;
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n != 1){
            if(n & 1) cnt+=1;
            n = n>>1;
        }
        if(n == 1) cnt+= 1;
        return cnt;
    }
};


// best approach


class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n != 1){
            cnt += (n&1);
            n = n>>1;
        }
        if(n == 1) cnt+= 1;
        return cnt;
    }
};