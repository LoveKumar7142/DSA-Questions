class Solution {
    public:
        string convert2Binary(int n){
            if(n == 0) return "0";
            string binary = "";
            while(n > 0){
                binary = char('0' + (n%2)) + binary;
                n/=2;
            }
            return binary
        }
};