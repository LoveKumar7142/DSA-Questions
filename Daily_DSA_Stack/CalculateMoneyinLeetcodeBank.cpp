class Solution {
public:
    int totalMoney(int n) {
        int cnt = 1;
        int money = 0;
        for(int i = 1;i<=n;i++){
            if(i%7 == 1){
                cnt = i/7 + 1;
                money+=cnt;
            }else {
                cnt++;
                money += cnt;
            }
        }
        return money == INT_MAX? INT_MAX : money;
    }
};