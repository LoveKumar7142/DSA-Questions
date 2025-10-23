class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() != 2){
            for(int i = 1;i<s.size();i++){
                s[i-1] = (s[i-1]+s[i])%10;
            }
            s.resize(s.size()-1);
        }
        return s[0] == s[1];
    }
};