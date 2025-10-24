class Solution {
private:
    bool balance(int num){
        vector<int> cnt(10);
        while(num > 0){
            int digit = num%10;
            cnt[digit]++;
            num/=10;
        }
        for(int d = 0; d<10;d++){
            if(cnt[d]>0 && cnt[d] != d) return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        for(int i = n+1;i<= 1224444;i++){
            if(balance(i)) return i;
        }
        return -1;
    }
};